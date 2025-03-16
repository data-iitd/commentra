#include <iostream>

int main() {
    int a[3];

    std::cin >> a[0] >> a[1] >> a[2];

    int five = 0;
    int seven = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] == 5) {
            five++;
        }
        if (a[i] == 7) {
            seven++;
        }
    }

    if (five == 2 && seven == 1) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
