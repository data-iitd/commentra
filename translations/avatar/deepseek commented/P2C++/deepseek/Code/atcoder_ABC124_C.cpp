#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> even, odd;

    for (size_t i = 0; i < s.length(); ++i) {
        if (i % 2 == 0) {
            even[s[i]]++;
        } else {
            odd[s[i]]++;
        }
    }

    int result = std::min(
        s.length() - (even['0'] + odd['1']),
        s.length() - (even['1'] + odd['0'])
    );

    std::cout << result << std::endl;

    return 0;
}

