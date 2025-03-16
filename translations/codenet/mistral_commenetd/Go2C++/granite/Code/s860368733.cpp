

#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    std::map<int, int> counter;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        if (h[a - 1] < h[b - 1]) {
            counter[a]++;
        } else if (h[a - 1] > h[b - 1]) {
            counter[b]++;
        } else if (h[a - 1] == h[b - 1]) {
            counter[a]++;
            counter[b]++;
        }
    }
    int result = n;
    for (auto const& [key, value] : counter) {
        result -= value;
    }
    std::cout << result << std::endl;
    return 0;
}

