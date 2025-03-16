#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> str(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> str[i];
    }

    for (int u = 0; u < 3; ++u) {
        int yes = 0;
        for (int i = 0; i < 3; ++i) {
            if ((str[u][i] == str[u][i + 1] && (str[u + 1][i] == str[u][i] || str[u + 1][i + 1] == str[u][i])) ||
                (str[u + 1][i] == str[u + 1][i + 1] && (str[u][i] == str[u + 1][i] || str[u][i + 1] == str[u + 1][i]))) {
                yes = 1;
                std::cout << "YES" << std::endl;
                break;
            }
        }
        if (yes == 1) {
            break;
        }
        if (yes == 0) {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

