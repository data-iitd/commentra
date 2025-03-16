#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> l(n, std::vector<char>(m));

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '.') {
                if ((i + j) % 2 == 0) {
                    l[i][j] = 'B';
                } else {
                    l[i][j] = 'W';
                }
            } else {
                l[i][j] = s[j];
            }
        }
    }

    for (const auto& c : l) {
        for (char ch : c) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }

    return 0;
}
