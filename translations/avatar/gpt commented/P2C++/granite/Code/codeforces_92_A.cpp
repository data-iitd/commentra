
#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    int i = 1;
    while (m >= i) {
        m -= i;
        i = (i % n) + 1;
    }

    std::cout << m << std::endl;
    return 0;
}
