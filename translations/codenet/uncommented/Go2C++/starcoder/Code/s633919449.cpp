#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MOD = 1000000007;

int main() {
	int N;
	cin >> N;

	switch (N % 10) {
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
		cout << "hon" << endl;
		break;
	case 0:
	case 1:
	case 6:
	case 8:
		cout << "pon" << endl;
		break;
	case 3:
		cout << "bon" << endl;
		break;
	}
}

