#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> m(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> m[i].first >> m[i].second;
    }

    std::sort(m.begin(), m.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    });

    for (int i = 1; i < n; ++i) {
        if (m[i].second > m[0].second) {
            std::cout << "Happy Alex" << std::endl;
            return 0;
        }
        m[0] = m[i];
    }

    std::cout << "Poor Alex" << std::endl;

    return 0;
}

