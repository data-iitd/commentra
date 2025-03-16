
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Data represents a structure holding a string.
struct Data {
	string X;
};

// Datas is a vector of Data structures.
typedef vector<Data> Datas;

// Len returns the length of the Datas vector.
int Len(Datas p) {
	return p.size();
}

// Swap swaps the elements at indices i and j.
void Swap(Datas& p, int i, int j) {
	Data temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

// Less returns true if the element at index i is less than the element at index j.
bool Less(Datas p, int i, int j) {
	return p[i].X < p[j].X;
}

// The main function reads N strings, sorts them, and prints the concatenated result.
int main() {
	int N, L;
	cin >> N >> L;
	Datas s(N);

	for (int i = 0; i < N; i++) {
		cin >> s[i].X;
	}

	//out(N, L, s);
	sort(s.begin(), s.end());
	//out(s);

	string ans = "";
	for (int i = 0; i < N; i++) {
		ans = ans + s[i].X;
	}
	cout << ans << endl;

	return 0;
}

