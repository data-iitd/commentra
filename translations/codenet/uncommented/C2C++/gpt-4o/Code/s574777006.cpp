#include <iostream>
#include <vector>

int main() {
    int n, q, sum = 0;
    std::cin >> n;

    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::cin >> q;
    std::vector<int> y(q);
    for (int i = 0; i < q; i++) {
        std::cin >> y[i];
    }

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            if (y[i] == x[j]) {
                sum++;
                break;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
