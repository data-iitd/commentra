#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string txt;
    std::getline(std::cin, txt);
    
    int cu = 0; // Count of uppercase letters
    int cl = 0; // Count of lowercase letters
    
    for (char z : txt) {
        if (std::islower(z)) {
            cl++;
        } else {
            cu++;
        }
    }
    
    std::string out;
    if (cu > cl) {
        for (char z : txt) {
            out += std::toupper(z);
        }
    } else {
        for (char z : txt) {
            out += std::tolower(z);
        }
    }
    
    std::cout << out << std::endl;
    return 0;
}

// <END-OF-CODE>
