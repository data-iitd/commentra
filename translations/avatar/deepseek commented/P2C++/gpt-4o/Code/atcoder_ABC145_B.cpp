#include <iostream>
#include <string>

int main() {
    // Take an integer input from the user
    int n;
    std::cin >> n;

    // Take a string input from the user
    std::string s;
    std::cin >> s;

    // Check if n is odd
    if (n % 2 != 0) {
        // Print 'No' if n is odd
        std::cout << "No" << std::endl;
    }
    // If n is even, compare the first half of the string with the second half
    else if (s.substr(0, n / 2) == s.substr(n / 2, n / 2)) {
        // Print 'Yes' if the first half is equal to the second half
        std::cout << "Yes" << std::endl;
    } else {
        // Print 'No' if the first half is not equal to the second half
        std::cout << "No" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
