#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> petals;
    for (int i = 0; i < n; ++i) {
        int petal;
        cin >> petal;
        petals.push_back(petal);
    }

    int contain_average = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = 0;
            set<int> in_set;
            for (int k = i; k <= j; ++k) {
                sum += petals[k];
                in_set.insert(petals[k]);
            }

            if (sum % (j + 1 - i) == 0) {
                int average = sum / (j + 1 - i);
                if (in_set.count(average)) contain_average++;
            }
        }
    }

    cout << contain_average << endl;

    return 0;
}