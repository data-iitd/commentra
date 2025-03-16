#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // Read the values of n and k from input

    string s;
    cin >> s; // Read the string s from input

    vector<int> count(26, 0); // Initialize a vector `count` with 26 zeros to count occurrences of each letter

    for (char c : s) {
        count[c - 'A']++; // Increment the corresponding count for each character
    }

    sort(count.rbegin(), count.rend()); // Sort the `count` vector in descending order

    int res = 0; // Initialize `res` to 0, which will be used to store the result

    for (int i = 0; i < 26; i++) {
        if (count[i] >= k) {
            res += k * k; // Calculate the result using the formula `k * k`
            cout << res << endl; // Print the result
            return 0; // Exit the program
        }

        k -= count[i]; // Subtract the current count from `k`
        res += count[i] * count[i]; // Add the square of the current count to `res`
    }

    cout << res << endl; // Print the final result `res`
    return 0;
}

// <END-OF-CODE>
