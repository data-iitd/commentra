#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> t(n + 1, 0);
    std::vector<int> a(n + 1, 0);
    std::vector<int> cnt(n + 1, 0);
    std::vector<int> ans;

    for (int i = 1; i <= n; ++i) {
        std::cin >> t[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        ++cnt[a[i]];
    }

    for (int i = 1; i <= n; ++i) {
        if (t[i] == 1) {
            std::vector<int> crt;
            int x = a[i];
            while (cnt[x] == 1) {
                crt.push_back(x);
                x = a[x];
            }
            if (crt.size() > ans.size()) {
                ans = crt;
            }
        }
    }

    std::reverse(ans.begin(), ans.end());
    std::cout << ans.size() << std::endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << ans[i];
    }
    std::cout << std::endl;

    return 0;
}
