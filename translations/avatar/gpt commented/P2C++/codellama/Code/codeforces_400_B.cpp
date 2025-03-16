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
        c.insert(s.find("S") - s.find("G"));
    }

    for (auto a : c) {
        if (a < 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::cout << c.size() << std::endl;

    return 0;
}

