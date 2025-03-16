#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read two integers n and k from input
    int n, k;
    std::cin >> n >> k;

    // Read the string s from input
    std::string s;
    std::cin >> s;

    // Initialize a vector to count occurrences of each letter (A-Z)
    std::vector<int> count(26, 0);

    // Count the occurrences of each character in the string
    for (char c : s) {
        count[c - 'A']++;
    }

    // Sort the count vector in descending order to prioritize higher counts
    std::sort(count.rbegin(), count.rend());

    // Initialize the result variable to accumulate the final score
    int res = 0;

    // Iterate through the sorted count vector
    for (int i = 0; i < 26; i++) {
        // If the current count is greater than or equal to k
        if (count[i] >= k) {
            // Add k squared to the result and print it
            res += k * k;
            std::cout << res << std::endl;
            return 0;  // Exit the program since we have found the result
        }

        // Decrease k by the current count
        k -= count[i];

        // Add the square of the current count to the result
        res += count[i] * count[i];
    }

    // Print the final result after processing all counts
    std::cout << res << std::endl;

    return 0;
}

// <END-OF-CODE>
