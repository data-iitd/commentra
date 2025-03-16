#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> ara(n);
    std::unordered_map<int, int> map;

    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        ara[i] = v;
        if (map.find(v) == map.end()) {
            map[v] = 1;
        } else {
            map[v]++;
        }
    }

    int max = 0;
    for (const auto& p : map) {
        max = std::max(max, p.second);
    }

    std::unordered_map<int, int> mm;
    for (int i = 0; i < n; ++i) {
        if (mm.find(ara[i]) == mm.end()) {
            mm[ara[i]] = 1;
            if (mm[ara[i]] == max) {
                std::cout << ara[i] << '\n';
                break;
            }
        } else {
            mm[ara[i]]++;
            if (mm[ara[i]] == max) {
                std::cout << ara[i] << '\n';
                break;
            }
        }
    }

    return 0;
}
