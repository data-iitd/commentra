#include <iostream>
#include <vector>
#include <string>

int main() {
    auto R = []() {
        int n, m, s, f;
        std::cin >> n >> m >> s >> f;
        return std::make_tuple(n, m, s, f);
    };

    int n, m, s, f;
    std::tie(n, m, s, f) = R();

    std::string res = "";
    int i = 1;
    int j = s;
    int t, l, r;
    int k = 1;

    while (j != f) {
        if (i > t && k < m) {
            std::cin >> t >> l >> r;
            k++;
        }
        if (i == t && (l <= j && j <= r || l <= j + (j < f ? 1 : -1) && j + (j < f ? 1 : -1) <= r)) {
            res += 'X';
        } else {
            res += (j < f ? 'R' : 'L');
            j += (j < f ? 1 : -1);
        }
        i++;
    }

    std::cout << res << std::endl;
    return 0;
}
