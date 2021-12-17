#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string cowphabet;
    cin >> cowphabet;

    string spoken;
    cin >> spoken;

    int index = 0;

    for (int i = 1;; ++i) {
        for (char c: cowphabet) {
            if (index == spoken.length()) {
                cout << i << endl;
                return 0;
            }

            if (spoken[index] == c) index++;
        }
    }
}