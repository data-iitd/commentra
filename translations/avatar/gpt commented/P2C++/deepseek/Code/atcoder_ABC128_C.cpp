#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> li(m);
    for (int i = 0; i < m; ++i) {
        int k;
        std::cin >> k;
        li[i].resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> li[i][j];
        }
    }

    std::vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> p[i];
    }

    std::set<int> q;
    for (const auto& vec : li) {
        for (int num : vec) {
            q.insert(num);
        }
    }

    std::set<int> r;
    for (int i = 1; i <= n; ++i) {
        r.insert(i);
    }

    std::set<int> v = r;
    for (int num : q) {
        v.erase(num);
    }

    long long ans = 0;
    std::set<int> s;
    for (int i = 0; i <= q.size(); ++i) {
        std::vector<bool> used(q.size(), false);
        std::function<void(int)> generate = [&](int pos) {
            if (pos == i) {
                std::set<int> s;
                for (int j = 0; j < q.size(); ++j) {
                    if (used[j]) {
                        s.insert(j);
                    }
                }
                bool valid = true;
                for (int j = 0; j < m; ++j) {
                    int count = 0;
                    for (int num : li[j]) {
                        if (s.count(num)) {
                            ++count;
                        }
                    }
                    if (count % 2 != p[j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ans += std::pow(2, v.size());
                }
                return;
            }
            if (pos < q.size()) {
                used[pos] = true;
                generate(pos + 1);
                used[pos] = false;
            }
            generate(pos + 1);
        };
        generate(0);
    }

    std::cout << ans << std::endl;
    return 0;
}
