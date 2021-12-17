#include <bits/stdc++.h>

using namespace std;


string direction(string path) {

    vector<char> cardinal_directions = {'N', 'E', 'S', 'W'};

    auto itr = find(cardinal_directions.begin(), cardinal_directions.end(), path[0]);
    int i;
    if (itr != cardinal_directions.end()) {
        i = itr - cardinal_directions.begin();
    } else {
        cerr << "Uh, oh!" << endl;
    }

    int count = 0;
    for (auto c: path.substr(1, path.length() - 1)) {
        int index1 = i - 1;
        if (index1 == -1) index1 = cardinal_directions.size() - 1;

        int index2 = i + 1;
        if (index2 == cardinal_directions.size()) index2 = 0;

        if (cardinal_directions[i] == c) {
            continue;
        } else if (cardinal_directions[index1] == c) {
            i = index1;
            count--;
        } else if (cardinal_directions[index2] == c) {
            i = index2;
            count++;
        } else {
            cerr << "Char is not right before or after..." << endl;
        }
    }

    if (count > 0) {
        return "CW";
    } else if (count < 0) {
        return "CCW";
    } else {
        cerr << "Count is equal to 0..." << endl;
        return "";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string path;
        cin >> path;
        cout << direction(path) << endl;
    }

    return 0;
}