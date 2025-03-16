
#include <iostream>
#include <set>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::set<int> c;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        int index_S = s.find('S');
        int index_G = s.find('G');

        int difference = index_S - index_G;
        c.insert(difference);
    }

    bool has_negative = false;
    for (auto it = c.begin(); it!= c.end(); it++) {
        if (*it < 0) {
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
