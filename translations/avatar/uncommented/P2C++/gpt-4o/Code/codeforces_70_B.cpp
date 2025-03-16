#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // To ignore the newline character after the integer input
    std::string input;
    std::getline(std::cin, input);

    int ans = 1, sumL = 0;
    std::istringstream stream(input);
    std::string s;

    while (std::getline(stream, s, '.')) {
        // Split by '.', and handle other delimiters
        if (s.empty()) continue; // Skip empty strings
        s = s + '.'; // Add the delimiter back
        int L = s.length();
        
        if (L > 1) {
            if (L > n) {
                std::cout << "Impossible" << std::endl;
                return 0;
            }
            if (sumL + L + (sumL > 0) > n) {
                ans += 1;
                sumL = L;
            } else {
                sumL = sumL + L + (sumL > 0);
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
