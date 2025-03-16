#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::vector<std::pair<int, int>> menu;
    
    for (int i = 0; i < 5; ++i) {
        std::string m;
        std::cin >> m;
        int e = m.back() - '0'; // Get the last character and convert to int
        if (e == 0) {
            e = 10;
        }
        menu.push_back({std::stoi(m), e});
    }
    
    std::sort(menu.begin(), menu.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });
    
    int ans = 0;
    for (size_t i = 1; i < menu.size(); ++i) {
        ans += std::ceil(menu[i].first / 10.0) * 10;
    }
    
    std::cout << ans + menu[0].first << std::endl;

    return 0;
}

// <END-OF-CODE>
