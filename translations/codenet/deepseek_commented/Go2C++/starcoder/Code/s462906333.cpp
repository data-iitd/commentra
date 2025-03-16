#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------------------------

// const abcd = "abcdefghijklnmopqrstuvwxyz"
// const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// var dy = [...]int{1, 1, 0, -1, -1, -1, 0, 1}
// var dx = [...]int{0, 1, 1, 1, 0, -1, -1, -1}

// var dx = [...]int{0, 1, 0, -1}
// var dy = [...]int{1, 0, -1, 0}

const int INF = 1e14; // Define a large value to represent infinity for cost comparisons

// var mod = 1000000007

// ---------------------------------------------------------
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int x;
	cin >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> v(n);
	copy(a.begin(), a.end(), v.begin());
	int ans = INF; // Initialize the answer with a large value
	for (int k = 0; k < n; k++) { // Iterate over possible values of k
		int kans = 0; // Initialize the temporary answer for the current k
		for (int i = 0; i < n; i++) { // Iterate over each element in the array
			if (i - k < 0) { // If the index is out of bounds, wrap around
				v[i] = min(v[i], a[n + i - k]); // Update the value in v
			} else {
				v[i] = min(v[i], a[i - k]); // Update the value in v
			}
			kans += v[i]; // Add the updated value to the temporary answer
		}
		ans = min(ans, kans + k * x); // Update the final answer with the minimum cost
	}

	cout << ans << "\n"; // Print the minimum cost found
}

// ---------------------------------------------------------

// Pair is liked C++ pair
struct Pair {
	int a, b;
};

// Pairs is sorted by []Pair struct
struct Pairs {
	vector<Pair> v;
	bool operator()(const Pair &a, const Pair &b) {
		if (a.a < b.a) {
			return true;
		} else if (a.a == b.a) {
			return a.b < b.b;
		}
		return false;
	}
};

// -------------------------------

// ---------- buffered reader -----------------------------------------
class bufferedReader {
public:
	int p;
	int sz;
	char buf[10000];
	FILE *in;
	bufferedReader() {
		in = fopen("input.txt", "r");
		p = 0;
		sz = 0;
		fillBuf();
	}
	void fillBuf() {
		sz = fread(buf, 1, 10000, in);
	}
	int nextInt() {
		int v = 0;
		while (p < sz && buf[p] =='') {
			p++;
		}
		if (p >= sz) {
			fillBuf();
		}
		if (p >= sz) {
			return -1;
		}
		v = 0;
		while (p < sz && buf[p]!='') {
			v = v*10 + (buf[p] - '0');
			p++;
		}
		return v;
	}
	string next() {
		string v;
		while (p < sz && buf[p] =='') {
			p++;
		}
		if (p >= sz) {
			fillBuf();
		}
		if (p >= sz) {
			return v;
		}
		while (p < sz && buf[p]!='') {
			v += buf[p];
			p++;
		}
		return v;
	}
	string Line() {
		string v;
		while (p < sz && buf[p] =='') {
			p++;
		}
		if (p >= sz) {
			fillBuf();
		}
		if (p >= sz) {
			return v;
		}
		while (p < sz) {
			v += buf[p];
			p++;
		}
		return v;
	}
};

// ---------------------------------------------------------

// ---------- main() function -----------------------------------------
int main() {
	bufferedReader br;
	int n = br.nextInt();
	int x = br.nextInt();
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = br.nextInt();
	}
	vector<int> v(n);
	copy(a.begin(), a.end(), v.begin());
	int ans = INF; // Initialize the answer with a large value
	for (int k = 0; k < n; k++) { // Iterate over possible values of k
		int kans = 0; // Initialize the temporary answer for the current k
		for (int i = 0; i < n; i++) { // Iterate over each element in the array
			if (i - k < 0) { // If the index is out of bounds, wrap around
				v[i] = min(v[i], a[n + i - k]); // Update the value in v
			} else {
				v[i] = min(v[i], a[i - k]); // Update the value in v
			}
			kans += v[i]; // Add the updated value to the temporary answer
		}
		ans = min(ans, kans + k * x); // Update the final answer with the minimum cost
	}

	cout << ans << "\n"; // Print the minimum cost found
}

// ---------------------------------------------------------

// 