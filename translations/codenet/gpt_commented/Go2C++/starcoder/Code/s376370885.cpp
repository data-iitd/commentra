// by syu
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cctype>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <complex>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ciso646>
using namespace std;

// Initialize a new Scanner for reading input from standard input (cin)
struct Scanner {
	int b;
	int n;
	char buf[1048576];
	Scanner() {
		scanf("%d", &b);
		n = 0;
		while (scanf("%s", buf + n) == 1) {
			n += strlen(buf + n) + 1;
		}
	}
	int Int() {
		int x;
		scanf("%d", &x);
		return x;
	}
} in;

int main() {
	// Read two integers n and k from the input
	int n = in.Int();
	int k = in.Int();
	
	// Check if n is divisible by k
	if (n % k == 0) {
		// If n is divisible by k, print 0
		printf("0\n");
	} else {
		// If n is not divisible by k, print 1
		printf("1\n");
	}
}

// 