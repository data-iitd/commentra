
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::string s;
    std::cin >> s;
    int l = 2019;
    std::vector<int> m(l + 1, 0);
    m[0] = 1;
    int a = 0, r = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        a = (a + (s[i] - '0') * pow(10, s.size() - i - 1, l)) % l;
        m[a]++;
        r += m[a];
    }
    std::cout << r << std::endl;
    return 0;
}

