#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::getline(std::cin, s); // Read the newline character
    std::getline(std::cin, s); // Read the actual string

    int sa = 0;
    for (char c : s) {
        if (c == '-') {
            sa++;
        }
    }

    sa = std::min(n - sa, sa);

    std::vector<std::string> ss;

    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;

        b -= a;

        if (b % 2 == 1 && b <= sa * 2) {
            ss.push_back("1\n");
        } else {
            ss.push_back("0\n");
        }
    }

    for (const std::string& line : ss) {
        std::cout << line;
    }

    return 0;
}

