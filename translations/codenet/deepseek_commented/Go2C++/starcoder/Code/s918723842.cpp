#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cctype>
#include <climits>
#include <bitset>
#include <utility>
#include <sstream>
#include <iterator>
#include <type_traits>

using namespace std;

// Initializes a new Scanner instance to read from standard input.
class Scanner {
public:
	Scanner() {
		r = new istream(cin.rdbuf());
	}
	
	// Reads the next token from the input buffer.
	string Next() {
		while (isspace(*r)) r++;
		start = r;
		while (!isspace(*r)) r++;
		return string(start, r);
	}
	
	// Reads the next line from the input buffer.
	string NextLine() {
		string s;
		getline(*r, s);
		return s;
	}
	
	// Reads the next integer from the input buffer.
	int NextInt() {
		int v;
		scanf("%d", &v);
		return v;
	}
	
	// Reads the next 64-bit integer from the input buffer.
	long long NextInt64() {
		long long v;
		scanf("%lld", &v);
		return v;
	}
	
	// Reads the next float from the input buffer.
	double NextFloat() {
		double v;
		scanf("%lf", &v);
		return v;
	}
	
	// Reads the next array of integers from the input buffer.
	vector<int> NextIntArray() {
		vector<int> v;
		string s = Next();
		stringstream ss(s);
		int i;
		while (ss >> i) v.push_back(i);
		return v;
	}
	
	// Reads the next array of 64-bit integers from the input buffer.
	vector<long long> NextInt64Array() {
		vector<long long> v;
		string s = Next();
		stringstream ss(s);
		long long i;
		while (ss >> i) v.push_back(i);
		return v;
	}
	
	// Reads the next map of integers from the input buffer.
	map<int, bool> NextMap() {
		map<int, bool> m;
		string s = Next();
		stringstream ss(s);
		int i;
		while (ss >> i) m[i] = true;
		return m;
	}

private:
	istream *r;
	string start;
};

// Returns the maximum of two integers.
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

int main() {
	Scanner sc;
	
	// Reads three integers H, W, and N from the standard input.
	int H = sc.NextInt();
	int W = sc.NextInt();
	int N = sc.NextInt();
	
	// Determines the maximum of H and W and assigns it to A.
	int A = max(H, W);
	
	// Calculates the result by dividing N by A and rounding up.
	// This is done by adding N-1 to the division result and then performing integer division by A.
	printf("%d\n", (N + A - 1) / A);
}

