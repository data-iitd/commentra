#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    std::unordered_map<int, int> counter;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;

        if (h[a - 1] < h[b - 1]) {
            ++counter[a];
        } else if (h[a - 1] > h[b - 1]) {
            ++counter[b];
        } else {
            ++counter[a];
            ++counter[b];
        }
    }

    std::cout << n - counter.size() << std::endl;

    return 0;
}
