#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> dt;
    bool x = true;

    for (char i : s) {
        dt[i]++;
    }

    int cnt = 0;
    x = true;

    for (auto& pair : dt) {
        if (pair.second % 2 != 0 && cnt < 1) {
            cnt++;
        } else if (pair.second % 2 != 0 && cnt >= 1) {
            x = false;
            break;
        }
    }

    if (x) {
        std::cout << "First" << std::endl;
    } else if (!x && s.length() % 2 == 0) {
        std::cout << "Second" << std::endl;
    } else if (!x && s.length() % 2 != 0) {
        std::cout << "First" << std::endl;
    }

    return 0;
}
