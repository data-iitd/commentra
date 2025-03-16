#include <iostream>
#include <string>
#include <algorithm>

int main() {
    long long number;
    std::cin >> number;
    long long ans = -1, value = 0;
    int mask = 2;

    while (value < number) {
        std::string s = std::bitset<32>(mask++).to_string(); // Get binary representation
        s = s.substr(1); // Remove the leading zero
        int zeros = std::count(s.begin(), s.end(), '0');

        if (zeros != s.length() - zeros) continue;

        std::replace(s.begin(), s.end(), '0', '4');
        std::replace(s.begin(), s.end(), '1', '7');
        value = std::stoll(s);
    }

    std::cout << value << std::endl;
    return 0;
}

// <END-OF-CODE>
