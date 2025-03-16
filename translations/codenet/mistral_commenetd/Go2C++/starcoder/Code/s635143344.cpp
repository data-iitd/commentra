
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> in(3);

	cin >> in[0] >> in[1] >> in[2];

	sort(in.begin(), in.end());

	cout << in[2] * 10 + in[1] + in[0] << endl;

	return 0;
}

