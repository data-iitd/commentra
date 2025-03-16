
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <numeric>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> li(m);
    for (auto &u : li) {
        int k;
        std::cin >> k;
        u.resize(k);
        for (auto &v : u) {
            std::cin >> v;
        }
    }
    
    std::vector<int> p(m);
    for (auto &v : p) {
        std::cin >> v;
    }
    
    std::set<int> q;
    for (const auto &u : li) {
        for (const auto &v : u) {
            q.insert(v);
        }
    }
    
    std::set<int> r;
    for (int i = 1; i <= n; ++i) {
        r.insert(i);
    }
    
    std::set<int> v;
    std::set_difference(r.begin(), r.end(), q.begin(), q.end(), std::inserter(v, v.begin()));
    
    int ans = 0;
    for (int i = 0; i <= q.size(); ++i) {
        for (const auto &s : itertools::combinations(q, i)) {
            bool ok = true;
            for (int j = 0; j < m; ++j) {
                std::set<int> t(s);
                for (const auto &u : li[j]) {
                    t.erase(u);
                }
                if (t.size() % 2!= p[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += 1 << v.size();
            }
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}

