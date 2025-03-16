

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    // Read the values of n and k from input

    string s;
    cin >> s;
    // Read the string s from input

    vector<int> count(26, 0);
    // Initialize a vector `count` with 26 zeros to count occurrences of each letter

    for (char c : s) {
        count[c - 'A']++;
    }
    // Iterate over each character in the string `s`, calculate its index in the `count` vector, and increment the corresponding count

    sort(count.rbegin(), count.rend());
    // Sort the `count` vector in descending order

    int res = 0;
    // Initialize `res` to 0, which will be used to store the result

    for (int i = 0; i < 26; i++) {
        if (count[i] >= k) {
            res += k * k;
            cout << res << endl;
            return 0;
        }
        // If the current count is greater than or equal to `k`, calculate the result using the formula `k * k` and print it, then return from the function

        k -= count[i];
        res += count[i] * count[i];
    }
    // If the current count is less than `k`, subtract the current count from `k` and add the square of the current count to `res`

    cout << res << endl;
    // Print the final result `res`

    return 0;
}
// End of C++ code

