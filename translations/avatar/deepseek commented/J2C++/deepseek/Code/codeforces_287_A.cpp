#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> str(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> str[i];
    }

    bool yes = false;
    for (int u = 0; u < 3; ++u) {
        for (int i = 0; i < 3; ++i) {
            if ((str[u][i] == str[u][i + 1] && (str[u + 1][i] == str[u][i] || str[u + 1][i + 1] == str[u][i])) ||
                (str[u + 1][i] == str[u + 1][i + 1] && (str[u][i] == str[u + 1][i] || str[u][i + 1] == str[u + 1][i]))) {
                yes = true;
                std::cout << "YES" << std::endl;
                break;
            }
        }
        if (yes) {
            break;
        }
    }

    if (!yes) {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

