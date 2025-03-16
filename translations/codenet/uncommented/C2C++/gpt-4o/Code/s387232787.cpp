#include <iostream>
#include <cstring>

int c[26] = {0};

int main() {
    char str[1200];
    while (std::cin >> str) {
        for (char *p = str; *p; p++) {
            if ('a' <= *p && *p <= 'z') {
                c[*p - 'a']++;
            } else if ('A' <= *p && *p <= 'Z') {
                c[*p - 'A']++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        std::cout << static_cast<char>('a' + i) << " : " << c[i] << std::endl; 
    }
    return 0;
}

// <END-OF-CODE>
