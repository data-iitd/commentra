#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

const int mod = 1e9 + 7;

int main() {
    std::vector<std::string> week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    std::string s;
    std::cin >> s;

    int index = -1;
    for (int i = 0; i < week.size(); ++i) {
        if (s == week[i]) {
            index = i;
            break;
        }
    }

    std::cout << 7 - index << std::endl;
    return 0;
}

// <END-OF-CODE>
