#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {
    char s[26];

    std::cin >> s;

    for (int j = 0; j < strlen(s); j++) {
        for (int i = 0; i < strlen(s); i++) {
            if ((i != j) && (s[i] == s[j])) {
                std::cout << "no" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "yes" << std::endl;

    return 0;
}

// <END-OF-CODE>
