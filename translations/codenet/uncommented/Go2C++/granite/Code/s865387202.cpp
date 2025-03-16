
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

struct city {
    int prefecture;
    int position;
    int year;
};

typedef vector<city*> cities;
typedef map<int, cities> cMap;

bool compare(city* c1, city* c2) {
    return c1->year < c2->year;
}

int main() {
    int n, m;
    cin >> n >> m;
    cMap h;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        auto it = h.find(x);
        if (it == h.end()) {
            h[x] = cities{new city{x, i, y}};
        } else {
            it->second.push_back(new city{x, i, y});
        }
    }

    vector<string> results(m);

    for (auto it = h.begin(); it!= h.end(); it++) {
        sort(it->second.begin(), it->second.end(), compare);
        for (int i = 0; i < it->second.size(); i++) {
            results[it->second[i]->position] = to_string(it->second[i]->prefecture) + to_string(i + 1);
        }
    }
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    return 0;
}

