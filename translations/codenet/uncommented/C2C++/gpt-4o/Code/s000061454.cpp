#include <iostream>

int main() {
    int a, b, n;
    int sum;
    int i, j;
    while (true) {
        if (std::cin >> a >> b >> n) {
            a -= a / b * b;
            sum = 0;
            for (i = 1; i <= n; i++) {
                a *= 10;
                for (j = 9; j >= 0; j--) {
                    if (b * j <= a) break;
                }
                a -= b * j;
                sum += j;
            }
            std::cout << sum << std::endl;
        } else {
            break;
        }
    }
    return 0;
}

// <END-OF-CODE>
