#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main() {
    std::string s;
    int l = 2019;
    std::vector<int> m(l, 0);
    int a = 0, r = 0;

    std::cin >> s;

    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());

    for (size_t i = 0; i < reversed_s.size(); ++i) {
        a += (reversed_s[i] - '0') * std::pow(10, i);
        a %= l;
        r += m[a];
        m[a]++;
    }

    std::cout << r << std::endl;

    return 0;
}
