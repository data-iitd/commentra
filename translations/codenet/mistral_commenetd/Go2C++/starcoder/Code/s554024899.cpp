
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <type_traits>
#include <climits>
#include <cfloat>
#include <ciso646>
#include <cstdalign>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <initializer_list>
#include <iosfwd>
#include <iomanip>
#include <ios>
#include <istream>
#include <iterator>
#include <limits>
#include <locale>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

// Helper function to find the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Define a scanner structure
struct scanner {
	int p;
	int buf[1000];
	int r;
	int readLine() {
		p = 0;
		r = 0;
		while (true) {
			int c = getchar();
			if (c == EOF) {
				return 0;
			}
			if (c == '\n') {
				return 1;
			}
			buf[p++] = c;
		}
	}
	int nextInt() {
		int result = 0;
		bool neg = false;
		while (true) {
			int c = buf[p++];
			if (c == '-') {
				neg = true;
			} else if (c =='') {
				break;
			} else {
				result = result * 10 + c - '0';
			}
		}
		if (neg) {
			return -result;
		}
		return result;
	}
	int next() {
		int result = 0;
		while (true) {
			int c = buf[p++];
			if (c =='') {
				break;
			}
			result = result * 10 + c - '0';
		}
		return result;
	}
};

int main() {
	scanner sc;
	int x = sc.nextInt();
	int y = sc.nextInt();
	int xt = 0;
	int yt = 0;
	vector<vector<int>> a = { {1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2} };
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] == x) {
				xt = i;
			}
			if (a[i][j] == y) {
				yt = i;
			}
		}
	}
	if (xt == yt) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}

