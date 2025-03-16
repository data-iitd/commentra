#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int n, m;
    ss >> n >> m;

    std::vector<std::string> ans(n);

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        std::string temp = "";

        for (int j = 0; j < m; ++j) {
            if (line[j] == '-') {
                temp += "-";
            } else {
                if ((i + j) % 2 == 1) {
                    temp += "W";
                } else {
                    temp += "B";
                }
            }
        }

        ans[i] = temp;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}
