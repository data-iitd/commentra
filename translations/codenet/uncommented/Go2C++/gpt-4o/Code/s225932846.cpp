#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;
    for (int i = 2; i <= S.length(); i += 2) {
        if (S.substr(0, (S.length() - i) / 2) == S.substr((S.length() - i) / 2, (S.length() - i) / 2)) ) {
            std::cout << (S.length() - i) << std::endl;
            break;
        }
    }
    return 0;
}

// <END-OF-CODE>
