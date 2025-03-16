
#include <iostream>
#include <algorithm>

int main() {
    int a, b;
    std::cin >> a >> b;

    int c = 0;

    for (int i = 0; i < 2; i++) {
        c += std::max(a, b);
        if (a >= b) {
            a--;
        } else {
            b--;
        }
    }

    std::cout << c << std::endl;

    return 0;
}
