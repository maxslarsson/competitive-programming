#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> heights;
    for (int i = 0; i < n; ++i) {
        int height;
        cin >> height;
        heights.push_back(height);
    }

    vector<int> limits;
    for (int i = 0; i < n; ++i) {
        int limit;
        cin >> limit;
        limits.push_back(limit);
    }

    sort(heights.rbegin(), heights.rend());

    ll count = 1;
    for (int i = 0; i < heights.size(); ++i) {
        int h = heights[i];
        int stalls_fit = 0;
        for (auto l: limits) {
            if (h <= l) stalls_fit++;
        }
        count *= stalls_fit - i;
    }

    cout << count << endl;

    return 0;
}