#include <iostream>

int you(int, int);

int main() {
    int x, y, z;
    std::cin >> x >> y;
    if (x >= y) z = you(x, y);
    else z = you(y, x);
    std::cout << z << std::endl;
    return 0;
}

int you(int x, int y) {
    int z;
    while (true) {
        z = x % y;
        x = y;
        y = z;
        if (y <= 0) break;
    }
    return x;
}

// <END-OF-CODE>
