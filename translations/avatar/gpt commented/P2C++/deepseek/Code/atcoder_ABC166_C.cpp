#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore();  // Ignore the newline character after reading n and m

    std::vector<int> h(n);
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    for (int i = 0; i < n; ++i) {
        iss >> h[i];
    }

    std::unordered_map<int, std::vector<int>> path;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int c = 0;
    for (const auto& [i, v] : path) {
        bool f = false;
        for (int j : v) {
            if (h[i - 1] <= h[j - 1]) {
                f = true;
                break;
            }
        }
        if (!f) {
            ++c;
        }
    }

    std::cout << c << std::endl;
    return 0;
}

