#include <iostream>
#include <vector>
#include <string>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    std::set<int> differences;
    for (const auto& s : grid) {
        int first_S = s.find('S');
        int first_G = s.find('G');
        if (first_S == std::string::npos || first_G == std::string::npos) {
            std::cout << -1 << std::endl;
            return 0;
        }
        differences.insert(first_S - first_G);
    }

    std::cout << differences.size() << std::endl;
    return 0;
}
