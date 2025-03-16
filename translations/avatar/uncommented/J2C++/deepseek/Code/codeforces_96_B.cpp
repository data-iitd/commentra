#include <iostream>
#include <string>
#include <bitset>

int main() {
    long number;
    std::cin >> number;
    long ans = -1, value = 0;
    int mask = 2;
    while (value < number) {
        std::string s = std::bitset<32>(mask++).to_string().substr(1);
        int zeros = 0;
        for (char c : s) if (c == '0') zeros++;
        if (zeros != s.length() - zeros) continue;
        for (char& c : s) c = (c == '0') ? '4' : '7';
        value = std::stol(s);
    }
    std::cout << value << std::endl;
    return 0;
}
