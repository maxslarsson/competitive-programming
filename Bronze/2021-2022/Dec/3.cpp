#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

int K;

int solve(pi pos, const vector<vector<char>> &grid, int turns, bool down) {
    int rows = grid.size();
    int cols = grid[grid.size() - 1].size();

    // Out of bounds
    if (pos.first == rows || pos.second == cols) return 0;
    // If reached turn limit
    if (turns > K) return 0;
    // If haybale
    if (grid[pos.first][pos.second] == 'H') return 0;
    // Not possible to reach ending when not in same col or row and made max number of turns
    if (turns == K && pos.first != rows - 1 && pos.second != cols - 1) return 0;

    // cur row == bottom row
    // cur col == right col
    if (pos.first == rows - 1 && pos.second == cols - 1) {
        return 1;
    }

    return solve({pos.first + 1, pos.second}, grid, down ? turns : turns + 1, true) +
           solve({pos.first, pos.second + 1}, grid, down ? turns + 1 : turns, false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        cin >> K;

        vector<vector<char>> grid;
        for (int k = 0; k < n; ++k) {
            vector<char> line;
            for (int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                line.push_back(c);
            }
            grid.push_back(line);
        }

        cout << solve({0, 1}, grid, 0, false) + solve({1, 0}, grid, 0, true) << endl;
    }

    return 0;
}