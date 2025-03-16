#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::set<int> c;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        int posS = s.find('S');
        int posG = s.find('G');
        c.insert(posS - posG);
    }

    bool hasNegative = false;
    for (const auto& a : c) {
        if (a < 0) {
            hasNegative = true;
            break;
        }
    }

    if (hasNegative) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << c.size() << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
