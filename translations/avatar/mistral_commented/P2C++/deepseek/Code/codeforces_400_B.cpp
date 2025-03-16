#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::set<int> c;

    for (int i = 0; i < m; ++i) {
        std::string s;
        std::cin >> s;

        int index_S = s.find('S');
        int index_G = s.find('G');

        int difference = index_S - index_G;
        c.insert(difference);
    }

    bool has_negative = false;
    for (auto a : c) {
        if (a < 0) {
            has_negative = true;
            break;
        }
    }

    if (has_negative) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << c.size() << std::endl;
    }

    return 0;
}
