
#include <iostream>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;

    if (n < 1) {
        if (m < 1) {
            std::cout << n << " " << m << std::endl;
            return 0;
        }
        std::cout << "Impossible" << std::endl;
        return 0;
    }

    if (m > n) {
        int min = m;
        int max = n + m - 1;
        std::cout << min << " " << max << std::endl;
    }

    if (m <= n) {
        int min = n;
        int max = n + m - 1;
        if (m == 0) {
            max = n;
        }
        std::cout << min << " " << max << std::endl;
    }

    return 0;
}
