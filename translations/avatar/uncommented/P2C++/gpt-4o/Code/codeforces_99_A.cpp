#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string l;
    std::getline(std::cin, l);
    
    size_t dotPos = l.find('.');
    std::string s = l.substr(0, dotPos);
    std::string p = l.substr(dotPos + 1);
    
    int i = p[0] - '0'; // Convert char to int

    if (s.back() == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;
    } else if (s.back() != '9' && i < 5) {
        std::cout << s << std::endl;
    } else {
        s = std::to_string(std::stoi(s) + 1);
        std::cout << s << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
