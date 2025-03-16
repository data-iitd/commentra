#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto readInts = []() {
        int n, m, s, f;
        std::cin >> n >> m >> s >> f;
        return std::make_tuple(n, m, s, f);
    };

    auto [n, m, s, f] = readInts();

    int d = (s < f) ? 1 : -1;
    char c = (d == 1) ? 'R' : 'L';

    std::string res;
    int i = 1;
    int j = s;

    int t, l, r;
    int k = 1;

    while (j != f) {
        if (i > t && k < m) {
            std::cin >> t >> l >> r;
            k++;
        }

        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res += 'X';
        } else {
            res += c;
            j += d;
        }

        i++;
    }

    std::cout << res << '\n';

    return 0;
}
