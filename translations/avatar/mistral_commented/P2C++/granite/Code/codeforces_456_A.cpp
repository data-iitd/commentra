

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> m(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        m[i] = {a, b};
    }
    std::sort(m.begin(), m.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] > b[1];
    });
    std::vector<int> a = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i][1] > a[1]) {
            std::cout << "Happy Alex" << std::endl;
            return 0;
        }
        a = m[i];
    }
    std::cout << "Poor Alex" << std::endl;
    return 0;
}

