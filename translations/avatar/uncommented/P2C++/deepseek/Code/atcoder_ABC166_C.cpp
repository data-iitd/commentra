#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> p(n);
    std::vector<int> h(n);
    std::unordered_map<int, int> hp;
    std::unordered_map<int, std::vector<int>> path;

    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
        hp[p[i]] = h[i];
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int c = 0;
    for (const auto& item : path) {
        int i = item.first;
        const std::vector<int>& v = item.second;
        bool f = false;
        for (int j : v) {
            if (hp[i] <= hp[j]) {
                f = true;
                break;
            }
        }
        if (!f) {
            ++c;
        }
    }

    std::cout << c << std::endl;
    return 0;
}
