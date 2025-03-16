
#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;

    // Read an integer input from the user
    std::cin >> n;

    // Read a string input from the user
    std::cin >> s;

    // Check if the length of the string is odd
    if (n % 2!= 0) {
        // If the length is odd, print 'No' since it cannot be split into two equal halves
        std::cout << "No" << std::endl;
    }
    // Check if the first half of the string is equal to the second half
    else if (s.substr(0, n / 2) == s.substr(n / 2, n / 2)) {
        // If both halves are equal, print 'Yes'
        std::cout << "Yes" << std::endl;
    }
    else {
        // If the halves are not equal, print 'No'
        std::cout << "No" << std::endl;
    }

    return 0;
}
