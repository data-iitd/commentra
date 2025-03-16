

#include <iostream>
#include <regex>

int main() {
    int n;
    std::cin >> n;
    int ans = 1, sumL = 0;
    std::string s;
    std::regex re("[.?!]");
    while (std::getline(std::cin, s)) {
        s = std::regex_replace(s, re, ".");
        int L = s.length();
        if (L > 1) {
            if (L > n) {
                std::cout << "Impossible" << std::endl;
                return 0;
            }
            if (sumL + L + (sumL > 0) > n) {
                ans++;
                sumL = L;
            } else {
                sumL = sumL + L + (sumL > 0);
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

