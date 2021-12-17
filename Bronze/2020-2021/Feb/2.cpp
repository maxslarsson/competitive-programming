#include <bits/stdc++.h>

using namespace std;

int DX[] = {0, 0, 1, -1};
int DY[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<pair<int, int>, int> neighbors;
    set<pair<int, int>> points;
    set<pair<int, int>> comfy;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        points.insert({x, y});

        int neigh = 0;
        for (int j = 0; j < 4; j++) {
            int newx = x + DX[j];
            int newy = y + DY[j];
            pair<int, int> adj = {newx, newy};

            neighbors[adj]++;
            bool adj_exists = points.count(adj);
            if (adj_exists) {
                neigh++;
                if (neighbors[adj] == 3) {
                    comfy.insert(adj);
                } else {
                    comfy.erase(adj);
                }
            }
        }

        neighbors[{x, y}] = neigh;
        if (neigh == 3) {
            comfy.insert({x, y});
        } else {
            comfy.erase({x, y});
        }

        cout << comfy.size() << endl;
    }
}
