#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> m(n, std::vector<int>(2));
    for (int i = 0; i < n; ++i) {
        std::cin >> m[i][0] >> m[i][1];
    }

    std::sort(m.begin(), m.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] > b[0];
    });

    std::vector<int> a = m[0];

    for (const auto& i : m) {
        if (i[1] > a[1]) {
            std::cout << "Happy Alex" << std::endl;
            return 0;
        }
        a = i;
    }

    std::cout << "Poor Alex" << std::endl;

    return 0;
}

