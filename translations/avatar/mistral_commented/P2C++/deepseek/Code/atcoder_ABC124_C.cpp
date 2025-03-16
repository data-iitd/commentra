#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> even, odd;
    for (size_t i = 0; i < s.size() / 2; ++i) {
        ++even[s[i]];
    }
    for (size_t i = s.size() / 2; i < s.size(); ++i) {
        ++odd[s[i]];
    }

    int result = std::min(s.size() - (even['0'] + odd['1']), s.size() - (even['1'] + odd['0']));
    std::cout << result << std::endl;

    return 0;
}
