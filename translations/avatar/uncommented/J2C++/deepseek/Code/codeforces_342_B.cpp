#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<std::string> input;
    std::string token;
    while (std::getline(iss, token, ' ')) {
        input.push_back(token);
    }
    int m = std::stoi(input[1]);
    int s = std::stoi(input[2]);
    int f = std::stoi(input[3]);
    int maxT = -1;
    std::map<int, std::vector<int>> map;
    while (m > 0) {
        std::getline(std::cin, line);
        std::istringstream mth_iss(line);
        std::vector<std::string> mth;
        while (std::getline(mth_iss, token, ' ')) {
            mth.push_back(token);
        }
        int k = std::stoi(mth[0]);
        map[k] = {std::stoi(mth[1]), std::stoi(mth[2])};
        maxT = std::max(maxT, k);
        m--;
    }
    std::stringstream actions;
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;
    int a = -1;
    int b = -1;
    for (int t = 1; t <= maxT; t++) {
        if (map.find(t) != map.end()) {
            a = map[t][0];
            b = map[t][1];
        }
        if (map.find(t) != map.end() && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions << 'X';
        } else {
            actions << M;
            cur += d;
        }
        if (cur == f) break;
    }
    while (cur != f) {
        actions << M;
        cur += d;
    }
    std::cout << actions.str() << std::endl;
    return 0;
}

