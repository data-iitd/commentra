#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
    std::string s;
    int l = 2019;
    std::cin >> s;

    std::vector<int> m(l, 0);
    m[0] = 1;
    int a = 0, r = 0;

    for (int i = 0; i < s.length(); ++i) {
        int e = s[s.length() - 1 - i];
        a += (e - '0') * std::pow(10, i) % l;
        r += m[a % l];
        m[a % l]++;
    }

    std::cout << r << std::endl;
    return 0;
}

