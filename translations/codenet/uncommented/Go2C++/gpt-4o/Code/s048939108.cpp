#include <iostream>
#include <string>

int main() {
    std::string S;
    std::getline(std::cin, S);
    
    if (S.rfind("YAKI", 0) == 0) { // Check if S starts with "YAKI"
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
