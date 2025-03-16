
#include <bits/stdc++.h>

using namespace std;

// Constants and variables declaration
const int inf = INT_MAX; // Constants for maximum signed integer value

// var mod = 1000000007; // Unused constant, can be removed

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1, 0}; // 8 directions for movement
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

// Global variables declaration
// Global scanner for reading input
// Global variables declaration

// ---------------------------------------------------------

// init function initializes the program
void init() {
	ios_base::sync_with_stdio(false); // Turn off synchronization with C standard I/O library
	cin.tie(0); // Turn off synchronization with C standard I/O library
	cout.tie(0); // Turn off synchronization with C standard I/O library
	srand(time(NULL)); // Seed random number generator with current time
}

// main function is the entry point of the program
int main() {
	// Read input N as a string
	string N;
	cin >> N;
	// Convert N to an integer
	int n = 0;
	for (int i = 0; i < N.length(); i++) {
		n += (int)(N[i] - '0'); // Convert each digit to an integer and add to the sum
	}
	// Read input m as an integer
	int m;
	cin >> m;
	// Check if m is divisible by n
	if (m % n == 0) {
		cout << "Yes" << endl; // Print "Yes" if m is divisible by n
	} else {
		cout << "No" << endl; // Print "No" if m is not divisible by n
	}
}

// ---------------------------------------------------------

// Pair type definition for storing two integers
struct Pair {
	int a, b;
};

// Pairs type definition for storing a slice of Pair
struct Pairs {
	vector<Pair> v;
};

// Implement Len, Swap, and Less methods for sorting Pairs based on the second element
int Len(Pairs p) {
	return p.v.size();
}
void Swap(Pairs p, int i, int j) {
	Pair t = p.v[i];
	p.v[i] = p.v[j];
	p.v[j] = t;
}
bool Less(Pairs p, int i, int j) {
	return p.v[i].b < p.v[j].b; // Sort based on the second element
}

// ------int methods-------------------------
bool in(int c, int a, int z) {
	return c >= a && c < z; // Check if c is within the range [a, z)
}
bool out(int c, int a, int z) {
	return!in(c, a, z); // Check if c is outside the range [a, z)
}
int btoi(bool b) {
	if (b) {
		return 1; // Convert boolean to integer: 1 for true, 0 for false
	}
	return 0;
}
bool itob(int a) {
	return a!= 0; // Convert integer to boolean: true for non-zero, false for zero
}
int max(int a, int b) {
	return a > b? a : b; // Find the maximum integer among the given integers
}
int min(int a, int b) {
	return a < b? a : b; // Find the minimum integer among the given integers
}
int sum(vector<int> a) {
	int r = 0;
	for (int i = 0; i < a.size(); i++) {
		r += a[i]; // Calculate the sum of all integers in the given slice
	}
	return r;
}
int pro(vector<int> a) {
	int r = 1;
	for (int i = 0; i < a.size(); i++) {
		r *= a[i]; // Calculate the product of all integers in the given slice
	}
	return r;
}

vector<int> fill(vector<int> a, int n) {
	for (int i = 0; i < a.size(); i++) {
		a[i] = n; // Fill the given slice with the given integer value
	}
	return a;
}
pair<int, int> minmax(int a, int b) {
	if (a > b) {
		return {b, a}; // Return the minimum and maximum integers among the given integers
	}
	return {a, b};
}

int abs(int a) {
	if (a < 0) {
		return -a; // Calculate the absolute value of an integer
	}
	return a;
}

// ---------- buffered scanner -----------------------------------------
struct scanner {
	int p;
	char buf[10000];
	int len;
	int lim;
	FILE *fin;
	scanner() {
		fin = stdin;
		len = 0;
		lim = 0;
		p = 0;
	}
	void readLine() {
		if (fgets(buf, 10000, fin) == NULL) {
			lim = 0;
			return;
		}
		lim = strlen(buf);
		for (int i = lim - 1; i >= 0; i--) {
			if (buf[i] == '\n') {
				lim = i;
				break;
			}
		}
		lim++;
		len = 0;
		p = 0;
	}
	void pre() {
		if (p >= lim) {
			readLine();
		}
	}
	string next() {
		string result = "";
		while (p < lim && buf[p] =='') {
			p++;
		}
		if (p >= lim) {
			return result;
		}
		while (p < lim && buf[p]!='') {
			result += buf[p++];
		}
		return result;
	}
	int Int() {
		int result = 0;
		bool neg = false;
		pre();
		if (p >= lim) {
			return result;
		}
		if (buf[p] == '-') {
			neg = true;
			p++;
		}
		while (p < lim && buf[p] >= '0' && buf[p] <= '9') {
			result = result*10 + (buf[p] - '0');
			p++;
		}
		if (neg) {
			return -result;
		}
		return result;
	}
	vector<int> Ints(int n) {
		vector<int> result(n);
		for (int i = 0; i < n; i++) {
			result[i] = Int();
		}
		return result;
	}
	int Int64() {
		long long result = 0;
		bool neg = false;
		pre();
		if (p >= lim) {
			return result;
		}
		if (buf[p] == '-') {
			neg = true;
			p++;
		}
		while (p < lim && buf[p] >= '0' && buf[p] <= '9') {
			result = result*10 + (buf[p] - '0');
			p++;
		}
		if (neg) {
			return -result;
		}
		return result;
	}
	vector<long long> Int64s(int n) {
		vector<long long> result(n);
		for (int i = 0; i < n; i++) {
			result[i] = Int64();
		}
		return result;
	}
	long long Uint64() {
		long long result = 0;
		pre();
		if (p >= lim) {
			return result;
		}
		while (p < lim && buf[p] >= '0' && buf[p] <= '9') {
			result = result*10 + (buf[p] - '0');
			p++;
		}
		return result;
	}
	vector<long long> Uint64s(int n) {
		vector<long long> result(n);
		for (int i = 0; i < n; i++) {
			result[i] = Uint64();
		}
		return result;
	}
	double Float64() {
		double result = 0;
		bool neg = false;
		pre();
		if (p >= lim) {
			return result;
		}
		if (buf[p] == '-') {
			neg = true;
			p++;
		}
		while (p < lim && buf[p] >= '0' && buf[p] <= '9') {
			result = result*10 + (buf[p] - '0');
			p++;
		}
		if (p < lim && buf[p] == '.') {
			p++;
			double div = 10;
			while (p < lim && buf[p] >= '0' && buf[p] <= '9') {
				result += (buf[p] - '0') / div;
				div *= 10;
				p++;
			}
		}
		if (neg) {
			return -result;
		}
		return result;
	}
	vector<double> Float64s(int n) {
		vector<double> result(n);
		for (int i = 0; i < n; i++) {
			result[i] = Float64();
		}
		return result;
	}
};

// 