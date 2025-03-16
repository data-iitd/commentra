#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }
    int a, b;
    std::unordered_set<int> counter;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        if (h[a - 1] < h[b - 1]) {
            counter.insert(a);
        } else if (h[a - 1] > h[b - 1]) {
            counter.insert(b);
        } else if (h[a - 1] == h[b - 1]) {
            counter.insert(a);
            counter.insert(b);
        }
    }
    std::cout << n - counter.size() << std::endl;
    return 0;
}

