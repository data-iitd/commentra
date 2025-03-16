#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int n = std::count(s.begin(), s.end(), 'o');
    std::cout << 700 + n * 100 << std::endl;

    return 0;
}

// <END-OF-CODE>
