#include <iostream>
#include <cstring>

int main() {
    int n;
    char s[10010];
    std::cin >> n;
    std::cin.ignore(); // To ignore the newline character after reading n

    while (n--) {
        std::cin.getline(s, 1010);
        char* c;
        while ((c = strstr(s, "Hoshino")) != nullptr) {
            *(c + 6) = 'a';
        }
        std::cout << s << std::endl;
    }
    return 0;
}

// <END-OF-CODE>
