#include <bits/stdc++.h>

using namespace std;

bool remove_first(vector<int> &ids, bool even) {
    for (int i = 0; i < ids.size(); i++) {
        if (even && ids[i] % 2 == 0) {
            ids.erase(ids.begin() + i);
            return true;
        } else if (!even && ids[i] % 2 != 0) {
            ids.erase(ids.begin() + i);
            return true;
        }
    }
    return false;
}

int recursive(vector<int> &ids, bool even = true) {


    // 1. If even, or odd number, choose that, continue with ids - the one chosen
    // 2. If even, find two odd numbers, choose them, if odd, choose an odd number
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ids;
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        ids.push_back(id);
    }

    bool even = true;
    int groups = 0;

    while (!ids.empty()) {
        bool found = remove_first(ids, even);
        bool found2 = false;

        if (!found && even) {
            found = remove_first(ids, false);
            bool found2 = remove_first(ids, false);
            if (!found2) {
                // Then there is one odd number left, so remove one of the groups to make ONE even group from TWO odd groups.
                // Thus, the remaining odd number can be added to the new even group, creating a new odd group
                groups--;
                break;
            }
        } else if (!found) {
            cerr << "Uh oh..." << endl;
        }

        if (!found) {
            // Then there is one number left, an even number, which can be added to any of the even groups group
            break;
        }

        even = !even;
        groups++;
    }

    cout << groups << endl;

    return 0;
}