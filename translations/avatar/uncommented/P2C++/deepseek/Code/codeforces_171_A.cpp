#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int x = std::max(a.size(), b.size());
    a.resize(x, '0');
    b.resize(x, '0');
    std::string s;
    int c = 0;
    for (int i = 0; i < x; ++i) {
        int d = (b[i] - '0') + (a[i] - '0') + c;
        if (d > 9) {
            s += std::to_string(d)[1];
            c = 1;
        } else {
            s += std::to_string(d)[0];
            c = 0;
        }
    }
    if (c == 1) {
        s += '1';
    }
    std::string result;
    for (int i = s.size() - 1; i >= 0; --i) {
        result += s[i];
    }
    std::cout << std::stoi(result) << std::endl;
    return 0;
}
