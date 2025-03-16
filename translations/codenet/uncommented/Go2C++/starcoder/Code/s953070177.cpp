#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> aa(n+2);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> aa[i+1];
		sum += abs(aa[i+1] - aa[i]);
	}
	sum += abs(aa[n+1] - aa[n]);

	for (int i = 1; i < n+1; i++) {
		int ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1]);
		cout << ans << endl;
	}
	return 0;
}

