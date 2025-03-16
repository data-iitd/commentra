#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i];
    }

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < n; ++i) {
        a += elements[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        b += elements[i];
    }

    for (int i = 0; i < n - 2; ++i) {
        c += elements[i];
    }

    int x = a - b;
    int y = b - c;

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    return 0;
}

