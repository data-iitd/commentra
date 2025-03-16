
#include <iostream>
#include <string>
#include <map>

int main() {
    std::string s;
    std::cin >> s;

    std::map<char, int> dt;
    for (char c : s) {
        if (dt.find(c)!= dt.end()) {
            dt[c]++;
        } else {
            dt[c] = 1;
        }
    }

    int cnt = 0;
    bool x = true;
    for (auto const& [key, value] : dt) {
        if (value % 2!= 0 && cnt < 1) {
            cnt++;
        } else if (value % 2!= 0 && cnt >= 1) {
            x = false;
            break;
        }
    }

    if (x) {
        std::cout << "First" << std::endl;
    } else if (!x && s.length() % 2 == 0) {
        std::cout << "Second" << std::endl;
    } else if (!x && s.length() % 2!= 0) {
        std::cout << "First" << std::endl;
    }

    return 0;
}
