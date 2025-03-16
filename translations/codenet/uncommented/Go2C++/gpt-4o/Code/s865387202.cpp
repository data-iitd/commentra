#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <sstream>

struct City {
    int prefecture;
    int position;
    int year;
};

using Cities = std::vector<City>;
using CityMap = std::map<int, Cities>;

int main() {
    int n, m;
    std::cin >> n >> m;
    CityMap cityMap;

    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        cityMap[x].push_back({x, i, y});
    }

    std::vector<std::string> results(m);

    for (auto& pair : cityMap) {
        Cities& cities = pair.second;
        std::sort(cities.begin(), cities.end(), [](const City& a, const City& b) {
            return a.year < b.year;
        });

        for (size_t idx = 0; idx < cities.size(); ++idx) {
            const City& ci = cities[idx];
            std::ostringstream oss;
            oss << std::setw(6) << std::setfill('0') << ci.prefecture
                << std::setw(6) << std::setfill('0') << (idx + 1);
            results[ci.position] = oss.str();
        }
    }

    for (const auto& result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
