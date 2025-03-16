#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> ans(n);

    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        std::string temp = "";

        for (int j = 0; j < m; j++) {
            if (str[j] == '-') {
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

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}
