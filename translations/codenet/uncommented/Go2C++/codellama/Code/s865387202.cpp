
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct City {
	int prefecture;
	int position;
	int year;
};

struct Cities : vector<City*> {
	bool operator()(const City* a, const City* b) {
		return a->year < b->year;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	map<int, Cities> h;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		auto it = h.find(x);
		if (it == h.end()) {
			h[x] = Cities{{x, i, y}};
		} else {
			h[x].push_back(new City{x, i, y});
		}
	}

	vector<string> results(m);

	for (auto& v : h) {
		sort(v.second.begin(), v.second.end(), Cities());
		for (int idx = 0; idx < v.second.size(); idx++) {
			results[v.second[idx]->position] = to_string(v.first) + to_string(idx + 1);
		}
	}
	for (auto& r : results) {
		cout << r << endl;
	}
	return 0;
}

