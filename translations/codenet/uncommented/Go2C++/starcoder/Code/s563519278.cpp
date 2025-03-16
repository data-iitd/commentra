#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	int a;
	for (int i = 1; i < N; i++) {
		cin >> a;
		v[a-1]++;
	}
	for (int e : v) {
		cout << e << endl;
	}
	return 0;
}

