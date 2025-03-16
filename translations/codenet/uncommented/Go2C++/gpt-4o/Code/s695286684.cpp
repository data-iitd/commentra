#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    size_t pos = s.find("2017");
    if (pos != std::string::npos) {
        s.replace(pos, 4, "2018");
    }
    std::cout << s << std::endl;
    return 0;
}

// <END-OF-CODE>
