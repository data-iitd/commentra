
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

struct City {
    int prefecture;
    int position;
    int year;
};

bool compareCities(const City& c1, const City& c2) {
    return c1.year < c2.year;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::map<int, std::vector<City>> citiesMap;

    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;

        if (citiesMap.find(x) == citiesMap.end()) {
            citiesMap[x] = std::vector<City>();
        }

        City city = {x, i, y};
        citiesMap[x].push_back(city);
    }

    std::vector<std::string> results(m);

    for (auto& entry : citiesMap) {
        std::vector<City>& cities = entry.second;
        std::sort(cities.begin(), cities.end(), compareCities);

        for (int i = 0; i < cities.size(); i++) {
            std::stringstream ss;
            ss << std::setw(6) << std::setfill('0') << cities[i].prefecture;
            ss << std::setw(6) << std::setfill('0') << i + 1;
            results[cities[i].position] = ss.str();
        }
    }

    for (const auto& result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}

// 