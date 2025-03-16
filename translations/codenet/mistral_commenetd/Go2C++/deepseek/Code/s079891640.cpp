#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    for (size_t i = 0; i < s.length(); ++i) {
        if (s.find(s[i], i + 1) != std::string::npos) {
            std::cout << "no" << std::endl;
            return 0;
        }
    }

    std::cout << "yes" << std::endl;
    return 0;
}

