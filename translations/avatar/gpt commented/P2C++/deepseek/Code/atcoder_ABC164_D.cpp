#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    int l = 2019;
    std::cin >> s;

    std::vector<int> m(l, 0);
    int a = 0, r = 0;
    m[0] = 1;

    for (int i = 0; i < s.length(); ++i) {
        a += (s[s.length() - 1 - i] - '0') * pow(10, i);
        a %= l;
        r += m[a];
        m[a]++;
    }

    std::cout << r << std::endl;
    return 0;
}

