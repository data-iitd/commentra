#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    int x = std::accumulate(w.begin(), w.end(), 0);
    std::vector<int> d;
    for (int i = 0; i < n; ++i) {
        if ((x - w[i]) * 1.0 / (n - 1) == w[i]) {
            d.push_back(i + 1);
        }
    }
    std::cout << d.size() << std::endl;
    if (!d.empty()) {
        std::ostringstream oss;
        for (size_t i = 0; i < d.size() - 1; ++i) {
            oss << d[i] << " ";
        }
        oss << d.back();
        std::cout << oss.str() << std::endl;
    }
    return 0;
}
