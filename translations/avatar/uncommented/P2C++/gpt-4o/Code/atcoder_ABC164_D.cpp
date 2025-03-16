#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::string s;
    std::cin >> s;
    const int l = 2019;
    std::vector<int> m(1, 0);
    m.resize(l + 1, 0);
    int a = 0, r = 0;

    for (int i = 0; i < s.size(); ++i) {
        char e = s[s.size() - 1 - i];
        a += (e - '0') * static_cast<int>(pow(10, i)) % l;
        r += m[a % l];
        m[a % l]++;
    }

    std::cout << r << std::endl;
    return 0;
}

// <END-OF-CODE>
