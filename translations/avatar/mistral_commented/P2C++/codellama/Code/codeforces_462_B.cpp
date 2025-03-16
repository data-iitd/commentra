#######
# Code
#######

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Define input variables
    int n, k;
    cin >> n >> k;
    // n: number of characters in the string s
    // k: number of occurrences of a character we want to find

    string s;
    cin >> s;
    // s: string to be processed

    // Initialize a vector to store the count of each character
    vector<int> count(26, 0);

    // Iterate through each character in the string s
    for (char c : s) {
        // Increment the count of the character in the vector count
        count[c - 'A']++;
    }

    // Sort the count vector in descending order
    sort(count.begin(), count.end(), greater<int>());

    // Initialize result variable
    int res = 0;

    // Iterate through each character count in the vector count
    for (int i = 0; i < 26; i++) {
        // Check if the count of the current character is greater than or equal to k
        if (count[i] >= k) {
            // Calculate the result and print it
            res += k * k;
            cout << res << endl;
            // Exit the loop as we have found the required characters
            return 0;
        }
        // Update the value of k by subtracting the count of the current character
        k -= count[i];
        // Add the square of the count of the current character to the result
        res += count[i] * count[i];
    }

    // Print the final result if no character is found with the required count
    cout << res << endl;

    return 0;
}

