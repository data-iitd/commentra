#include <iostream>
#include <cstring>

int main() {
    char str[30];
    std::cin.getline(str, 30);
    str[5] = ' ';
    str[13] = ' ';
    std::cout << str << std::endl;
    return 0;
}

// <END-OF-CODE>
