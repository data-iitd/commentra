// by syu
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (n % k == 0) {
		cout << 0 << endl;
	} else {
		cout << 1 << endl;
	}
	return 0;
}
