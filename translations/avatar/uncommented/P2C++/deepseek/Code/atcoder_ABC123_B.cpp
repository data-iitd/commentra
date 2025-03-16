#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::pair<int, int>> menu;
    for (int i = 0; i < 5; ++i) {
        std::string m;
        std::cin >> m;
        int e = m.back() - '0';
        if (e == 0) {
            e = 10;
        }
        menu.push_back({std::stoi(m), e});
    }
    std::sort(menu.begin(), menu.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });
    int ans = 0;
    for (int i = 1; i < menu.size(); ++i) {
        ans += std::ceil(static_cast<double>(menu[i].first) / 10) * 10;
    }
    std::cout << ans + menu[0].first << std::endl;
    return 0;
}

