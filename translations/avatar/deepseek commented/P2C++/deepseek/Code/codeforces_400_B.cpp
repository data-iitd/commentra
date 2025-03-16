#include <iostream>
#include <vector>
#include <set>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> grid(n);
    std::set<int> c;

    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    for (int i = 0; i < n; ++i) {
        int s_index = -1, g_index = -1;
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                s_index = j;
            } else if (grid[i][j] == 'G') {
                g_index = j;
            }
        }
        if (s_index != -1 && g_index != -1) {
            c.insert(s_index - g_index);
        }
    }

    for (int a : c) {
        if (a < 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::cout << c.size() << std::endl;

    return 0;
}

