
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
	string X;
};

struct Datas {
	vector<Data> v;
	int size() {
		return v.size();
	}
	void swap(int i, int j) {
		Data temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	}
	bool less(int i, int j) {
		return v[i].X < v[j].X;
	}
};

int main() {
	int N, L;
	cin >> N >> L;
	Datas s;
	for (int i = 0; i < N; i++) {
		Data d;
		cin >> d.X;
		s.v.push_back(d);
	}
	cout << N << " " << L << " " << s.v << endl;
	sort(s.v.begin(), s.v.end(), s.less);
	cout << s.v << endl;

	string ans = "";
	for (int i = 0; i < N; i++) {
		ans = ans + s.v[i].X;
	}
	cout << ans << endl;

	return 0;
}

