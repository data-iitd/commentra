#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::vector<int> vo(100010, 0);
    std::vector<int> ve(100010, 0);
    std::vector<int> vt(100010, 0);
    for (int i = 0; i < n; ++i) {
        ++vt[v[i]];
        if (i % 2 == 0) {
            ++ve[v[i]];
        } else {
            ++vo[v[i]];
        }
    }
    std::sort(vo.begin(), vo.end(), std::greater<int>());
    std::sort(ve.begin(), ve.end(), std::greater<int>());
    std::sort(vt.begin(), vt.end(), std::greater<int>());
    int ans = 0;
    if (vo[0] + ve[0] == vt[0]) {
        ans = std::min(n - vo[0] - ve[1], n - vo[1] - ve[0]);
    } else {
        ans = n - vo[0] - ve[0];
    }
    std::cout << ans << std::endl;
    return 0;
}

