#include <iostream>
#include <vector>
#include <numeric>
#include <sstream>

int main() {
    std::string a;
    std::getline(std::cin, a);

    if (std::count(a.begin(), a.end(), '1') == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::vector<int> counts;
        std::stringstream ss(a);
        std::string token;

        // Split the string by '1'
        while (std::getline(ss, token, '1')) {
            // Count '0's in the token and add 1
            counts.push_back(std::count(token.begin(), token.end(), '0') + 1);
        }

        // Calculate the product
        int result = std::accumulate(counts.begin(), counts.end(), 1, std::multiplies<int>());
        std::cout << result << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
