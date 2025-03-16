
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

struct city {
    int prefecture;
    int position;
    int year;
};

typedef std::vector<city*> cities;
typedef std::map<int, cities> cMap;

bool compareCities(const city* c1, const city* c2) {
    return c1->year < c2->year;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    cMap h;

    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;

        auto it = h.find(x);
        if (it == h.end()) {
            h[x] = cities();
        }

        city* c = new city();
        c->prefecture = x;
        c->year = y;
        c->position = i;

        h[x].push_back(c);
    }

    std::vector<std::string> results(m);

    for (auto& pair : h) {
        cities& v = pair.second;
        std::sort(v.begin(), v.end(), compareCities);

        for (int i = 0; i < v.size(); i++) {
            std::stringstream ss;
            ss << std::setw(6) << std::setfill('0') << v[i]->prefecture << std::setw(6) << std::setfill('0') << i + 1;
            results[v[i]->position] = ss.str();
        }
    }

    for (const auto& result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}

