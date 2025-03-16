#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    if (s.find('A') != std::string::npos && s.find('B') != std::string::npos) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
