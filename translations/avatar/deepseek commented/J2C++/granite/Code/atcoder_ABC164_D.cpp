

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.length();

    // Array to store remainders at each position
    vector<int> mod_arr(N);
    // Array to count occurrences of each remainder
    vector<int> mod_cnt(2019);
    // Radix initialized to 1 for the least significant digit
    int radix = 1;

    // Process each character in the string from right to left
    for (int i = 0; i < N; i++) {
        int tmp = ((int)S[N - 1 - i] - (int)'0') * radix % 2019;
        if (i!= 0) tmp = (tmp + mod_arr[i - 1]) % 2019;
        mod_arr[i] = tmp;
        mod_cnt[tmp]++;
        radix = radix * 10 % 2019;
    }

    // Calculate the number of valid pairs using combinatorics
    long long ans = 0;
    mod_cnt[0]++; // Ensure 0 is counted
    for (int i = 0; i < 2019; i++) {
        ans += mod_cnt[i] * (mod_cnt[i] - 1) / 2;
    }

    // Output the result
    cout << ans << endl;

    return 0;
}
