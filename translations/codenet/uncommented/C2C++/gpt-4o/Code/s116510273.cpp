#include <iostream>
#include <cstring>

int main() {
    char mes[101];
    std::cin >> mes;
    std::cout << mes[0] << strlen(mes) - 2 << mes[strlen(mes) - 1] << std::endl;

    return 0;
}

// <END-OF-CODE>
