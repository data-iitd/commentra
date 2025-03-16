#include <iostream>
#include <vector>
#include <string>

int main() {
    auto readInts = []() {
        int n, m, s, f;
        std::cin >> n >> m >> s >> f;
        return std::make_tuple(n, m, s, f);
    };

    auto [n, m, s, f] = readInts();

    std::string direction = (s < f) ? "R" : "L";
    std::string result = "";
    int i = 1;
    int j = s;
    int t, l, r;
    int k = 1;

    while (j != f) {
        if (i > t && k < m) {
            std::cin >> t >> l >> r;
            k++;
        }

        if (i == t && (l <= j && j <= r || l <= j + (s < f ? 1 : -1) && j + (s < f ? 1 : -1) <= r)) {
            result += 'X';
        } else {
            result += direction[0];
            j += (s < f) ? 1 : -1;
        }
        i++;
    }

    std::cout << result << std::endl;

    return 0;
}

