#include <iostream>
#include <cstring>

int main() {
    char str[21];
    int len;

    std::cin >> str;

    len = std::strlen(str);

    for (int i = len - 1; i >= 0; i--) {
        std::putchar(str[i]);
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
