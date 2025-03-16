#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate

int main() {
    int n, m, x;
    std::cin >> n >> m >> x;

    std::vector<std::vector<int>> c(n, std::vector<int>(m));
    for (auto& row : c) {
        for (auto& val : row) {
            std::cin >> val;
        }
    }

    int pre[n];
    std::iota(pre, pre + n, 0);

    std::vector<std::vector<int>> l;
    std::vector<int> rem;

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        for (auto j : std::vector<int>(pre, pre + i)) {
            std::vector<int> temp = {j};
            l.push_back(temp);
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < l.size(); ++j) {
            int ca = 0;
            for (auto ii : l[j]) {
                ca += c[ii][i - 1];
            }
            if (ca < x) {
                rem.insert(rem.begin(), j);
            }
        }
        if (!rem.empty()) {
            for (auto j : rem) {
                l.erase(l.begin() + j);
            }
            rem.clear();
        }
        if (l.empty()) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    for (auto& i : l) {
        int ca = 0;
        for (auto j : i) {
            ca += c[j][0];
        }
        if (ans == 0) {
            ans = ca;
        } else {
            ans = std::min(ans, ca);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

