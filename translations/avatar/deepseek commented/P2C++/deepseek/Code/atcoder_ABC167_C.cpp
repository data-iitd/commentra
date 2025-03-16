#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate

int main() {
    int n, m, x;
    std::cin >> n >> m >> x;

    std::vector<std::vector<int>> c(n, std::vector<int>(m + 1));
    for (auto& row : c) {
        for (auto& elem : row) {
            std::cin >> elem;
        }
    }

    int ans = -1;
    for (int mask = 1; mask < (1 << n); ++mask) {
        std::vector<int> skill_levels(m, 0);
        int total_cost = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                total_cost += c[i][0];
                for (int j = 1; j <= m; ++j) {
                    skill_levels[j - 1] += c[i][j];
                }
            }
        }

        bool meets_requirement = true;
        for (int j = 0; j < m; ++j) {
            if (skill_levels[j] < x) {
                meets_requirement = false;
                break;
            }
        }

        if (meets_requirement) {
            if (ans == -1 || total_cost < ans) {
                ans = total_cost;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
