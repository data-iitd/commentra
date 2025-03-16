#include <bits/stdc++.h>
using namespace std;

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
struct BIT {
	int n;
	vector<int> data;
	void init(int n) {
		this->n = n;
		data.resize(n);
	}
	void add(int p, int x) {
		p++;
		for(; p <= n; p += p & -p) {
			data[p-1] += x;
		}
	}
	int sum(int r) {
		int s = 0;
		for(; r > 0; r -= r & -r) {
			s += data[r-1];
		}
		return s;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l);
	}
};

// FenwickTree :
BIT* FenwickTree(int n) {
	BIT* ret = new BIT();
	ret->init(n);
	return ret;
}

// ** copy to here to your source code **
//
// 