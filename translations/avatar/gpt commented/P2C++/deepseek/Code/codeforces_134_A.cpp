#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

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

    std::cout << d.size() << '\n';

    std::ostringstream oss;
    for (size_t i = 0; i < d.size(); ++i) {
        if (i > 0) {
            oss << ' ';
        }
        oss << d[i];
    }
    std::cout << oss.str() << '\n';

    return 0;
}
