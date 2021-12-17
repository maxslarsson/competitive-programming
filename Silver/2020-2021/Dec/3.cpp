#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

int blame(int i, map<int, vector<int>> &stops) {
    if (!stops.count(i)) return 0;

    int sum = stops[i].size();
    for (auto s: stops[i]) {
        sum += blame(s, stops);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pi> all_cows;
    vector<pi> n_cows;
    vector<pi> e_cows;
    for (int i = 0; i < n; ++i) {
        char direction;
        int x, y;
        cin >> direction >> x >> y;

        all_cows.emplace_back(x, y);

        if (direction == 'E') e_cows.emplace_back(x, y);
        else if (direction == 'N') n_cows.emplace_back(x, y);
    }

    sort(n_cows.begin(), n_cows.end(), [](auto l, auto r) {
        return l.first < r.first;
    });

    sort(e_cows.begin(), e_cows.end(), [](auto l, auto r) {
        return l.second < r.second;
    });

    // Cow, which cow stopped it
    map<pi, vector<pi>> stops;
    set<pi> seen_nc;

    // Only makes sense to compare one that goes east, one that goes north
    for (auto ec: e_cows) {
        for (auto nc: n_cows) {
            // The nc can not intersect with another line if it has already stopped
            if (seen_nc.count(nc)) continue;

            int x1, y1, x2, y2;
            tie(x1, y1) = ec;
            tie(x2, y2) = nc;

            pi intersection = {x2, y1};
            int xi, yi;
            tie(xi, yi) = intersection;

            // Invalid - not in the "quadrant" formed by the two.
            if (xi < x1 || yi < y2) continue;

            int dist_from_ec = xi - x1;
            int dist_from_nc = yi - y2;

            // Could maybe break somewhere here (since its sorted) because the first intersection, will be the closest one
            if (dist_from_ec > dist_from_nc) {
                // If nc is closer, nc stops ec
                stops[nc].push_back(ec);

                // One was found, so the ec can not continue on intersecting with other nc's
                // Go to the next ec
                break;
            } else if (dist_from_ec < dist_from_nc) {
                // If ec is closer, ec stops nc
                stops[ec].push_back(nc);
                seen_nc.insert(nc);
            }
        }
    }

    map<int, vector<int>> new_stops;

    for (const auto &s: stops) {
        pi key;
        vector<pi> values;
        tie(key, values) = s;


        int new_key;
        vector<int> new_value;
        for (int i = 0; i < all_cows.size(); ++i) {
            if (all_cows[i] == key) new_key = i;
            for (auto v: values) {
                if (all_cows[i] == v) new_value.push_back(i);
            }
        }
        new_stops[new_key] = new_value;
    }


    for (int i = 0; i < all_cows.size(); ++i) {
        cout << blame(i, new_stops) << endl;
    }

    return 0;
}