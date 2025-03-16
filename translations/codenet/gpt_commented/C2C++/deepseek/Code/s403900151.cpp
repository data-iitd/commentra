#include <iostream>
#include <vector>

int main() {
    int n, r, p, c;
    int i, j, k, l;
    std::vector<int> a(51); // Vector to hold values

    while (true) {
        std::cin >> n >> r;
        
        if (n == 0 && r == 0)
            break;

        for (i = 0; i < n; i++)
            a[i] = i + 1;

        for (i = 0; i < r; i++) {
            std::cin >> p >> c;

            std::vector<int> b(c);
            for (j = 0; j < c; j++)
                b[j] = a[n - p - c + 1 + j];

            for (j = 0; j < p - 1; j++)
                a[n - p - c + 1 + j] = a[n - p + j + 1];

            for (j = n - p - c + 1 + j, k = 0; k < c; j++, k++) {
                a[j] = b[k];
            }
        }

        std::cout << a[n - 1] << std::endl;
    }
    
    return 0;
}
