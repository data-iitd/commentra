#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string a;
    std::getline(std::cin, a);
    
    // Replace commas with spaces
    for (char &c : a) {
        if (c == ',') {
            c = ' ';
        }
    }
    
    std::cout << a << std::endl;
    return 0;
}

// <END-OF-CODE>
