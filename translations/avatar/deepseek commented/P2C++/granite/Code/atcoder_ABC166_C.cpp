
#include <iostream>
#include <vector>
#include <map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    std::map<int, int> hp;
    for (int i = 0; i < n; i++) {
        int h;
        std::cin >> h;
        hp[p[i]] = h;
    }

    std::map<int, std::vector<int>> path;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int c = 0;
    for (auto const& [i, v] : path) {
        bool f = false;
        for (int j : v) {
            if (hp[i] <= hp[j]) {
                f = true;
                break;
            }
        }
        if (!f) {
            c++;
        }
    }

    std::cout << c << std::endl;

    return 0;
}
