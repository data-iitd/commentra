#include <iostream>
#include <string>

int main() {
    // Read an integer value from the user
    int n;
    std::cin >> n;

    // Read a string value from the user
    std::string s;
    std::cin >> s;

    // Check if n is odd
    if (n % 2 != 0) {
        std::cout << "No" << std::endl;
    }
    // Check if the first half of the string is equal to the second half
    else if (s.substr(0, n / 2) == s.substr(n / 2, n / 2)) {
        std::cout << "Yes" << std::endl;
    }
    // If the first half is not equal to the second half, print 'No'
    else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
