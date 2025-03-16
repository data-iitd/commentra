#include <iostream>
#include <cstdlib> // for abs

#define ABS(x) (((x) < (0)) ? (-(x)) : (x))

int main() {
    int N, t, x, y, nx = 0, ny = 0, nt = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> t >> x >> y;
        int tmp = t - nt - (ABS(x - nx) + ABS(y - ny));
        if (tmp < 0 || tmp % 2) {
            std::cout << "No" << std::endl;
            return 0;
        }
        nt = t; // Update nt to the current time
        nx = x; // Update nx to the current x position
        ny = y; // Update ny to the current y position
    }
    std::cout << "Yes" << std::endl;
    return 0;
}

// <END-OF-CODE>
