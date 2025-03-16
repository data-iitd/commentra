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
    std::string word;
    while (iss >> word) {
        input.push_back(word);
    }

    int m = std::stoi(input[1]);
    int s = std::stoi(input[2]);
    int f = std::stoi(input[3]);

    std::map<int, std::vector<int>> map;
    int maxT = -1;

    while (m > 0) {
        std::getline(std::cin, line);
        std::istringstream mth_iss(line);
        std::vector<std::string> mth;
        while (mth_iss >> word) {
            mth.push_back(word);
        }
        int k = std::stoi(mth[0]);
        map[k] = {std::stoi(mth[1]), std::stoi(mth[2])};
        maxT = std::max(maxT, k);
        m--;
    }

    std::string actions;
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;

    for (int t = 1; t <= maxT; t++) {
        if (map.find(t) != map.end()) {
            int a = map[t][0];
            int b = map[t][1];
            if ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b)) {
                actions += 'X';
            } else {
                actions += M;
                cur += d;
            }
            if (cur == f) break;
        } else {
            actions += M;
            cur += d;
        }
    }

    while (cur != f) {
        actions += M;
        cur += d;
    }

    std::cout << actions << std::endl;
    return 0;
}
