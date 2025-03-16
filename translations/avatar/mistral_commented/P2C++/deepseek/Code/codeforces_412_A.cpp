#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, k;
    std::string v;
    std::cin >> n >> k;
    std::cin >> v;

    std::vector<std::string> d = {"LEFT", "RIGHT"};
    bool f = k - 1 < n - k;
    int m = std::min(k - 1, n - k);
    std::vector<std::string> a;

    for (int i = 0; i < m; ++i) {
        a.push_back(d[!f]);
    }

    for (int i = 0; i < v.size(); i += 2 * f) {
        a.push_back("PRINT " + std::string(1, v[i]));
        a.push_back(d[f]);
    }

    for (size_t i = 0; i < a.size() - 1; ++i) {
        std::cout << a[i] << std::endl;
    }

    return 0;
}

