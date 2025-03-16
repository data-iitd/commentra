#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        a += value;
    }

    for (int i = 0; i < n - 1; i++) {
        int value;
        std::cin >> value;
        b += value;
    }

    for (int i = 0; i < n - 2; i++) {
        int value;
        std::cin >> value;
        c += value;
    }

    int x = a - b;
    int y = b - c;

    std::cout << x << "\n";
    std::cout << y << "\n";

    return 0;
}

// <END-OF-CODE>
