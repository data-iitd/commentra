#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }

    std::vector<int> d;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                sum += w[j];
            }
        }
        if (sum % (n - 1) == 0 && sum / (n - 1) == w[i]) {
            d.push_back(i + 1);
        }
    }

    std::cout << d.size() << std::endl;
    for (size_t i = 0; i < d.size(); ++i) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << d[i];
    }
    std::cout << std::endl;

    return 0;
}
