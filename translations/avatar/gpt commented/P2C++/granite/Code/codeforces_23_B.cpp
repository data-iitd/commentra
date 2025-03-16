
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;

        if (a < 2) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << a - 2 << std::endl;
        }
    }

    return 0;
}

