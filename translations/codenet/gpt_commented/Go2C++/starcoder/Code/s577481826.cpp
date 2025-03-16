#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <bitset>

using namespace std;

int main() {
	int a, b, ret;
	cin >> a >> b;
	ret = a + b;
	if (ret < (a - b)) {
		ret = a - b;
	}
	if (ret < (a * b)) {
		ret = a * b;
	}
	cout << ret << endl;
	return 0;
}

