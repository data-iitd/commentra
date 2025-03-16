#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <bitset>
#include <cctype>
#include <climits>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <limits>
#include <iomanip>
#include <cfloat>
#include <ciso646>
#include <ctime>

using namespace std;

int main() {
	int c[3][3];
	int a[3], b[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c[i][j];
		}
	}

	b[0] = c[0][0] - a[0];
	b[1] = c[0][1] - a[0];
	b[2] = c[0][2] - a[0];
	a[1] = c[1][0] - c[0][0];
	a[2] = c[2][0] - c[0][0];
	if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
		a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

