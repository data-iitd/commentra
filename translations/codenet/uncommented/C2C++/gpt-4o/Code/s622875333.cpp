#include <iostream>
#include <vector>

int main() {
    int n, r, p, c;
    
    while (true) {
        std::cin >> n >> r;
        if (n == 0 && r == 0) break;

        std::vector<int> a(n);
        std::vector<int> b(n);

        for (int i = 0; i < n; i++) {
            a[i] = n - i;
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < n; j++) {
                b[j] = a[j];
            }
            std::cin >> p >> c;

            for (int j = 0; j < c; j++) {
                a[j] = b[p - 1 + j];
            }

            for (int j = c; j < c + p - 1; j++) {
                a[j] = b[j - c];
            }
        }
        std::cout << a[0] << std::endl;
    }
    return 0;
}

// <END-OF-CODE>
