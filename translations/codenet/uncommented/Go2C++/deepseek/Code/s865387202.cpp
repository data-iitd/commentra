#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

struct City {
    int prefecture;
    int position;
    int year;
};

using Cities = std::vector<City*>;
using CMap = std::map<int, Cities>;

int main() {
    int n, m;
    std::cin >> n >> m;
    CMap h;
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        auto it = h.find(x);
        if (it == h.end()) {
            h[x] = {new City{x, y, i}};
        } else {
            it->second.push_back(new City{x, y, i});
        }
    }

    std::string results[m];

    for (auto& pair : h) {
        std::sort(pair.second.begin(), pair.second.end(), [](const City* a, const City* b) {
            return a->year < b->year;
        });
        for (size_t idx = 0; idx < pair.second.size(); ++idx) {
            char buffer[12];
            snprintf(buffer, sizeof(buffer), "%06d%06zu", pair.second[idx]->prefecture, idx + 1);
            results[pair.second[idx]->position] = std::string(buffer);
        }
    }

    for (const auto& result : results) {
        std::cout << result << '\n';
    }

    return 0;
}
