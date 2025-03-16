#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::string n;
    std::cin >> n;

    std::vector<std::string> a = { "10", "100", "1000", "10000", "100000" };
    int new_sum = 0;

    for (char c : n) {
        new_sum += c - '0'; // Convert char to int and sum
    }

    if (std::find(a.begin(), a.end(), n) != a.end()) {
        std::cout << 10 << std::endl;
    } else {
        std::cout << new_sum << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
