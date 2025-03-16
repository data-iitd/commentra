#include <iostream>
#include <cstring>

int main() {
    char S[6];
    std::cin >> S;
    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] == 'A' && S[i + 1] == 'C') {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}

// <END-OF-CODE>
