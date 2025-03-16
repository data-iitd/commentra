#include <iostream>
#include <string>
#include <set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> strings(n);
    for (auto& s : strings) {
        std::cin >> s;
    }

    std::set<int> differences;
    for (const auto& s : strings) {
        int s_index = s.find('S');
        int g_index = s.find('G');
        if (s_index != std::string::npos && g_index != std::string::npos) {
            int diff = s_index - g_index;
            if (diff < 0) {
                std::cout << -1 << std::endl;
                return 0;
            }
            differences.insert(diff);
        }
    }

    std::cout << differences.size() << std::endl;
    return 0;
}

