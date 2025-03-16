
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Data represents a single data entry with a string field.
struct Data {
	string X;
};

// Datas is a vector of Data, implementing sort.Interface.
struct Datas : vector<Data> {
	bool operator<(const Datas& other) const {
		return this->X < other.X;
	}
};

int main() {
	int N, L;
	cin >> N >> L;
	Datas s;
	s.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i].X;
	}
	sort(s.begin(), s.end());
	string ans = "";
	for (int i = 0; i < N; i++) {
		ans += s[i].X;
	}
	cout << ans << endl;
	return 0;
}

