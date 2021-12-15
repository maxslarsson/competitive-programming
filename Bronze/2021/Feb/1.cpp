#include <bits/stdc++.h>

using namespace std;


struct Rel {
    string first_cow;
    int direction;
    string zodiac;
    string last_cow;
};

int main() {
    int n;
    cin >> n;

    vector<Rel> rels;
    map<string, int> cows = {{"Bessie", 0}};
    vector<string> years = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

    for (int i=0; i<n; i++) {
        string first_cow, direction, zodiac, last_cow, empty;
        cin >> first_cow >> empty >> empty >> direction >> zodiac >> empty >> empty >> last_cow;
        int dir = direction == "next" ? 1 : -1;
        rels.push_back({first_cow, dir, zodiac, last_cow});
    }

    for (const auto& r : rels) {
        int years_before_bessie = cows[r.last_cow];

        int count = years_before_bessie;
        while (true) {
            count += r.direction;
            int size = years.size();
            int idx = ((count % size) + size) % size;
            if (years[idx] == r.zodiac) {
                break;
            }
        }
        cows[r.first_cow] = count;
    }

    cout << abs(cows["Elsie"]) << endl;

    return 0;
}