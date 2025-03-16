
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 複数ソートのサンプル
struct Country {
    int gold;
    int silver;
    int blonze;
};

vector<Country> stableSortExample() {
    vector<Country> country = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 3, 2},
        {1, 3, 3},
    };
    sort(country.begin(), country.end(), [](Country a, Country b) { return a.blonze > b.blonze; });
    sort(country.begin(), country.end(), [](Country a, Country b) { return a.silver > b.silver; });
    sort(country.begin(), country.end(), [](Country a, Country b) { return a.gold > b.gold; });
    return country;
}

int main() {
    vector<Country> country = stableSortExample();
    for (auto c : country) {
        cout << c.gold << " " << c.silver << " " << c.blonze << endl;
    }
    return 0;
}

