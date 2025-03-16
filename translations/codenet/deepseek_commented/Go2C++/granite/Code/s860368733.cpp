

#include <iostream>
#include <map>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    std::map<int, std::set<int>> counter;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        if (h[a - 1] < h[b - 1]) {
            counter[a].insert(b);
        } else if (h[a - 1] > h[b - 1]) {
            counter[b].insert(a);
        } else {
            counter[a].insert(b);
            counter[b].insert(a);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (counter.find(i) == counter.end()) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

