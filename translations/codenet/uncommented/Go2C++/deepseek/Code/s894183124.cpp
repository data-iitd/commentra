#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    int count = 0;
    size_t pos = 0;
    while ((pos = s.find("ABC", pos)) != std::string::npos) {
        count++;
        pos += 3; // Move past the found "ABC"
    }
    std::cout << count << std::endl;
    return 0;
}

