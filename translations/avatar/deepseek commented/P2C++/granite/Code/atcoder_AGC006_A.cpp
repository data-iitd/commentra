

#include <iostream>
#include <vector>

int main() {
    int n;  // Read the integer input `n`
    std::cin >> n;
    std::vector<char> s(n);  // Read the list `s` of length `n`
    std::vector<char> t(n);  // Read the list `t` of length `n`
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }

    // Check if the lists `s` and `t` are equal
    if (s == t) {
        std::cout << n << std::endl;  // If they are equal, print `n`
    } else {
        int cnt = 0;  // Initialize the counter `cnt` to 0
        // Compare elements of `s` and `t` starting from each index `i` of `s`
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                // If a mismatch is found, break out of the inner loop
                if (s[i + j]!= t[j]) {
                    break;
                }
                // If the end of the inner list is reached without breaking, set `cnt`
                if (j == n - i - 1) {
                    cnt = n - i;
                }
            }
        }
        // Print `2 * n - cnt`
        std::cout << 2 * n - cnt << std::endl;
    }

    return 0;
}
