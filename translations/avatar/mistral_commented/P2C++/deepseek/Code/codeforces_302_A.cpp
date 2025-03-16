#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::string input;
    std::getline(std::cin, input); // Read the newline character
    std::getline(std::cin, input); // Read the input string

    int sa = 0;
    for (char c : input) {
        if (c == '-') {
            sa++;
        }
    }

    sa = std::min(n - sa, sa);

    std::vector<char> ss;

    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;

        int diff = b - a;

        if (diff % 2 == 0 || diff > sa * 2) {
            ss.push_back('1');
        } else {
            ss.push_back('0');
        }
    }

    for (char c : ss) {
        std::cout << c;
    }

    return 0;
}
