#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cassert>

using namespace std;

int main() {
	int x;
	cin >> x;
	int i = 1;
	int sum = 0;
	while (true) {
		sum += i;
		if (sum >= x) {
			break;
		}
		i++;
	}
	cout << i << endl;
	return 0;
}

