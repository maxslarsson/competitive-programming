#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ps;
    ps.reserve(n);
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        ps.push_back(p);
    }
    vector<int> ts;
    ts.reserve(n);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        ts.push_back(t);
    }

    vector<int> diff;
    diff.reserve(n);
    for (int i = 0; i < n; ++i) {
        int cur_diff = ps[i] - ts[i];
        if (i == 0 || cur_diff != diff[diff.size() - 1]) diff.push_back(cur_diff);
    }

    int start = 0;
    int ops = 0;
    while (true) {
        // remove beginning zeros
        while (start != diff.size() && diff[start] == 0) ++start;

        if (start == diff.size()) break;

        int end = start;
        while (end != diff.size()) {
            if ((diff[start] > 0 && diff[end] > 0) || (diff[start] < 0 && diff[end] < 0)) ++end;
            else break;
        }

        int closest_to_zero;
        if (diff[start] > 0) {
            // Positive
            closest_to_zero = *min_element(diff.begin() + start, diff.begin() + end);
        } else {
            // Negative numbers
            closest_to_zero = *max_element(diff.begin() + start, diff.begin() + end);
        }

        for (auto it = diff.begin() + start; it < diff.begin() + end; ++it) {
            *it -= closest_to_zero;
        }

        ops += abs(closest_to_zero);
    }

    cout << ops << endl;

    return 0;
}