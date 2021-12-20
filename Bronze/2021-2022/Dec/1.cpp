#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<char> cows;
    cows.reserve(n);
    for (int i = 0; i < n; ++i) {
        char cow;
        cin >> cow;
        cows.push_back(cow);
    }

    ll throw_out = 0;
    for (int start = 0; start < cows.size() - 2; ++start) {
        map<char, int> seen;
        for (int i = 0; i < cows.size() - start; ++i) {
            ++seen[cows[start + i]];

            // Haven't established a window of 3 yet
            if (i < 2) continue;

                // We only see of one type of cow, so we need to throw out that picture
            else if (seen['G'] == 1 || seen['H'] == 1) ++throw_out;

                // Can't unsee cows, so no need to check the rest of the windows
            else if (seen['G'] > 1 && seen['H'] > 1) break;
        }
    }

    cout << throw_out << endl;

    return 0;
}