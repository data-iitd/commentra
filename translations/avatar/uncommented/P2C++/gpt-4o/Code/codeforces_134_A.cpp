#include <iostream>
#include <vector>
#include <numeric>

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
        if ((x - w[i]) / (n - 1) == w[i]) {
            d.push_back(i + 1);
        }
    }
    
    std::cout << d.size() << std::endl;
    for (size_t i = 0; i < d.size(); ++i) {
        std::cout << d[i];
        if (i < d.size() - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
