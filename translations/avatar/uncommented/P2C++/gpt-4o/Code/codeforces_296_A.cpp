#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> m(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> m[i];
    }

    bool possible = true;
    std::unordered_map<std::string, int> countMap;

    for (const auto& item : m) {
        countMap[item]++;
    }

    for (const auto& pair : countMap) {
        if (pair.second >= n / 2 + 1) {
            possible = false;
            break;
        }
    }

    std::cout << (possible ? "YES" : "NO") << std::endl;

    return 0;
}

// <END-OF-CODE>
