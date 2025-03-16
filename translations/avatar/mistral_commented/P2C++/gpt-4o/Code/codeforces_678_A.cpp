#include <iostream>

int main() {
    // Read two integers from standard input
    int vamshi, z;
    std::cin >> vamshi >> z;

    // Calculate the number of complete divisions of z into vamshi
    // Add 1 to account for the remainder
    // Multiply the result by z
    std::cout << (vamshi / z + 1) * z << std::endl;

    return 0;
}

// <END-OF-CODE>
