#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------------------------
// Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

// Define an infinite value for comparison
const int inf = 1e9;

// ---------------------------------------------------------

// Pair struct to hold a pair of integers
struct Pair {
	int a, b;
};

// Pairs is a slice of Pair structs
typedef vector<Pair> Pairs;

// Utility functions for various operations

// Check if a value is within a range
bool in(int c, int a, int z) {
	return c >= a && c < z;
}

// Check if a value is outside a range
bool out(int c, int a, int z) {
	return!in(c, a, z);
}

// Convert boolean to integer (1 for true, 0 for false)
int btoi(bool b) {
	if (b) {
		return 1;
	}
	return 0;
}

// Convert integer to boolean (non-zero to true, zero to false)
bool itob(int a) {
	return a!= 0;
}

// Return the maximum value from a list of integers
int max(int a, int b) {
	return a > b? a : b;
}

// Return the minimum value from a list of integers
int min(int a, int b) {
	return a < b? a : b;
}

// Return the maximum value from a list of integers
int max(int a, int b, int c) {
	return max(a, max(b, c));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c) {
	return min(a, min(b, c));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d) {
	return max(a, max(b, max(c, d)));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d) {
	return min(a, min(b, min(c, d)));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e) {
	return max(a, max(b, max(c, max(d, e))));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e) {
	return min(a, min(b, min(c, min(d, e))));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f) {
	return max(a, max(b, max(c, max(d, max(e, f)))));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f) {
	return min(a, min(b, min(c, min(d, min(e, f)))));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g) {
	return max(a, max(b, max(c, max(d, max(e, max(f, g))))));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g) {
	return min(a, min(b, min(c, min(d, min(e, min(f, g))))));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, h)))))));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, h)))))));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, i))))))));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, i))))))));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, j)))))))));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, j)))))))));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, k))))))))));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, k))))))))));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, l)))))))))));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, l)))))))))));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, m))))))))))));
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, m))))))))))));
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, n))))))))))))))
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, n))))))))))))))
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, o)))))))))))))))
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, o)))))))))))))))
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, max(o, p))))))))))))))))
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, min(o, p))))))))))))))))
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, max(o, max(p, q)))))))))))))))))
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, min(o, min(p, q)))))))))))))))))
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, max(o, max(p, max(q, r))))))))))))))))))
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, min(o, min(p, min(q, r))))))))))))))))))
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, max(o, max(p, max(q, max(r, s)))))))))))))))))))
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, min(o, min(p, min(q, min(r, s)))))))))))))))))))
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t) {
	return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, max(i, max(j, max(k, max(l, max(m, max(n, max(o, max(p, max(q, max(r, max(s, t))))))))))))))))))))
}

// Return the minimum value from a list of integers
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t) {
	return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, min(i, min(j, min(k, min(l, min(m, min(n, min(o, min(p, min(q, min(r, min(s, t))))))))))))))))))))
}

// Return the maximum value from a list of integers
int max(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, in