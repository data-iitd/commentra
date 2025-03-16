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

    std::pair<int, int> a = m[0];

    for (int i = 1; i < n; ++i) {
        if (m[i].second > a.second) {
            std::cout << "Happy Alex" << std::endl;
            return 0;
        }
        a = m[i];
    }

    std::cout << "Poor Alex" << std::endl;

    return 0;
}

