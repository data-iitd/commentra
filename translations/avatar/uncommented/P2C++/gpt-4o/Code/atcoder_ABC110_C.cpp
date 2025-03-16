#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::string run(const std::string& s, const std::string& t) {
    std::map<char, int> countS, countT;

    for (char c : s) {
        countS[c]++;
    }
    for (char c : t) {
        countT[c]++;
    }

    std::vector<int> ss, tt;
    for (const auto& pair : countS) {
        ss.push_back(pair.second);
    }
    for (const auto& pair : countT) {
        tt.push_back(pair.second);
    }

    std::sort(ss.begin(), ss.end());
    std::sort(tt.begin(), tt.end());

    if (ss == tt) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << run(s, t) << std::endl;
    return 0;
}

// <END-OF-CODE>
