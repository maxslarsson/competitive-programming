#include <bits/stdc++.h>

using namespace std;

const int N = 7;
int nums[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    int a = nums[0];
    int b = nums[1];
    // Last element
    int a_b_c = nums[N - 1];
    int c = a_b_c - a - b;

    cout << a << " " << b << " " << c << endl;

    return 0;
}