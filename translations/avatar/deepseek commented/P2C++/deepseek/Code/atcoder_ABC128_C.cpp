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
    
    int ans = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
        std::set<int> q;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                q.insert(i + 1);
            }
        }
        
        bool valid = true;
        for (int i = 0; i < m; ++i) {
            int count = 0;
            for (int switch_id : li[i]) {
                if (q.count(switch_id)) {
                    ++count;
                }
            }
            if (count % 2 != p[i]) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            ++ans;
        }
    }
    
    std::cout << ans << std::endl;
    return 0;
}
