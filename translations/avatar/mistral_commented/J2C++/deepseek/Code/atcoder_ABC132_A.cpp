#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> map;

    for (char c : s) {
        map[c]++;
    }

    bool ok = true;

    for (auto& p : map) {
        if (p.second != 2) {
            ok = false;
            break;
        }
    }

    if (ok && map.size() == 2) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
