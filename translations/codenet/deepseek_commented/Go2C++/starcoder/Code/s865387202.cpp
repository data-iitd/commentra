#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct city {
	int prefecture;
	int position;
	int year;
};

struct cities : vector<city> {
	bool operator()(const city &a, const city &b) {
		return a.year < b.year;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	map<int, cities> h;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		auto it = h.find(x);
		if (it == h.end()) {
			h[x] = cities{{x, i, y}};
		} else {
			h[x].push_back({x, i, y});
		}
	}

	vector<string> results(m);

	for (auto it = h.begin(); it!= h.end(); it++) {
		sort(it->second.begin(), it->second.end(), it->second);
		for (int i = 0; i < it->second.size(); i++) {
			results[it->second[i].position] = to_string(it->second[i].prefecture).append(to_string(i + 1));
		}
	}

	cout << strings::join(results, "\n") << endl;
}

