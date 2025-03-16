#include <bits/stdc++.h>

using namespace std;

// out is a utility function to print multiple values with a newline.
void out(const vector<string> &x) {
	for (const auto &s : x) {
		cout << s << endl;
	}
}

// Data represents a structure holding a string.
struct Data {
	string X;
};

// Datas is a slice of Data structures.
typedef vector<Data> Datas;

// The main function reads N strings, sorts them, and prints the concatenated result.
int main() {
	int N;
	cin >> N;
	int L;
	cin >> L;
	Datas s(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i].X;
	}
	out(N, L, s);
	sort(s.begin(), s.end(), [](Data a, Data b) {
		return a.X < b.X;
	});
	out(s);
	string ans = "";
	for (int i = 0; i < N; i++) {
		ans += s[i].X;
	}
	cout << ans << endl;
	return 0;
}

