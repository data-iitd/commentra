
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct City {
    int prefecture;
    int position;
    int year;
};

struct Cities {
    vector<City*> cities;
};

struct CitiesMap {
    map<int, Cities> cities;
};

int main() {
    int n, m;
    cin >> n >> m;
    CitiesMap h;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        auto it = h.cities.find(x);
        if (it == h.cities.end()) {
            h.cities[x] = Cities{{prefecture: x, year: y, position: i}};
        } else {
            h.cities[x].cities.push_back(&City{prefecture: x, year: y, position: i});
        }
    }

    vector<string> results(m);

    for (auto& v : h.cities) {
        sort(v.second.cities.begin(), v.second.cities.end(), [](City* a, City* b) {
            return a->year < b->year;
        });
        for (int idx = 0; idx < v.second.cities.size(); idx++) {
            results[v.second.cities[idx]->position] = to_string(v.first) + to_string(idx + 1);
        }
    }

    for (auto& r : results) {
        cout << r << endl;
    }

    return 0;
}

