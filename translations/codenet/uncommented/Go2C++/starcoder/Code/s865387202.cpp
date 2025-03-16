#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

struct city {
	int prefecture;
	int position;
	int year;
};

bool operator<(const city& lhs, const city& rhs) {
	return lhs.year < rhs.year;
}

int main() {
	int n, m;
	cin >> n >> m;
	map<int, vector<city>> h;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		auto it = h.find(x);
		if (it == h.end()) {
			h[x] = vector<city>{city{x, i, y}};
		} else {
			h[x].push_back(city{x, i, y});
		}
	}

	vector<string> results(m);

	for (auto it = h.begin(); it!= h.end(); it++) {
		auto& v = it->second;
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			results[v[i].position] = to_string(v[i].prefecture) + to_string(i + 1);
		}
	}

	for (auto& s : results) {
		cout << s << endl;
	}
}

