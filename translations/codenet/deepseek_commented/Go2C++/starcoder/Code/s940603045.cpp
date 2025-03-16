#include <bits/stdc++.h>
using namespace std;

// const abcd = "abcdefghijklmnopqrstuvwxyz"
// const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
const int dx[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
const int dy[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

const int inf = 1e9;

// var mod = 1000000007
// var next = newScanner()

// ---------------------------------------------------------
// Initializes logging and random number generator seed
void init() {
	// log.SetFlags(log.Lshortfile)
	// rand.Seed(time.Now().UnixNano())
}

// Main function reads a string, calculates digit sum, and checks divisibility
int main() {
	string N; // Read input string
	cin >> N;
	int n = 0; // Initialize sum of digits
	for (int i = 0; i < N.size(); i++) {
		n += int(N[i] - '0');
	}
	int m = stoi(N); // Convert input string to integer
	if (m % n == 0) { // Check if the number is divisible by the sum of its digits
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

// ---------------------------------------------------------

// Pair is a struct representing a pair of integers
struct Pair {
	int a, b;
};

// Pairs is a slice of Pair structs, implementing sort.Interface
struct Pairs {
	vector<Pair> v;
	int len() {
		return v.size();
	}
	void add(int a, int b) {
		v.push_back({a, b});
	}
	bool operator()(int i, int j) {
		return v[i].b < v[j].b;
	}
};

// ------int method-------------------------
bool in(int c, int a, int z) {
	return c >= a && c < z;
}
bool out(int c, int a, int z) {
	return!in(c, a, z);
}
int btoi(bool b) {
	if (b) {
		return 1;
	}
	return 0;
}
bool itob(int a) {
	return a!= 0;
}
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}
int sum(vector<int> a) {
	int r = 0;
	for (int i = 0; i < a.size(); i++) {
		r += a[i];
	}
	return r;
}
int pro(vector<int> a) {
	int r = 1;
	for (int i = 0; i < a.size(); i++) {
		r *= a[i];
	}
	return r;
}

vector<int> fill(int n, int a) {
	vector<int> r(a, n);
	return r;
}
pair<int, int> minmax(int a, int b) {
	if (a > b) {
		return {b, a};
	}
	return {a, b};
}

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

//
//int abs(int a) {
//	int mask = a >> 63;
//	return (a ^ mask) - mask;
//}

int ceil(int a, int b) {
	if (a % b!= 0) {
		return 1;
	}
	return 0;
}

void printStrings(vector<string> out) {
	for (int i = 0; i < out.size(); i++) {
		cout << out[i];
		if (i!= out.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
}
void printInts(vector<int> out) {
	for (int i = 0; i < out.size(); i++) {
		cout << out[i];
		if (i!= out.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
}

// ---------- buffered scanner -----------------------------------------
struct scanner {
	int p;
	char buf[10000];
	scanner() {
		p = 0;
		scanf(" ");
	}
	string next() {
		string result = "";
		while (p < 10000 && buf[p]!='') {
			result += buf[p++];
		}
		while (p < 10000 && buf[p] =='') {
			p++;
		}
		return result;
	}
	int Int() {
		return stoi(next());
	}
	vector<int> Ints(int n) {
		vector<int> result(n);
		for (int i = 0; i < n; i++) {
			result[i] = Int();
		}
		return result;
	}
	int Int64() {
		return stoll(next());
	}
	vector<int> Int64s(int n) {
		vector<int> result(n);
		for (int i = 0; i < n; i++) {
			result[i] = Int64();
		}
		return result;
	}
	uint64_t Uint64() {
		return stoull(next());
	}
	vector<uint64_t> Uint64s(int n) {
		vector<uint64_t> result(n);
		for (int i = 0; i < n; i++) {
			result[i] = Uint64();
		}
		return result;
	}
	float Float64() {
		return stod(next());
	}
	vector<float> Float64s(int n) {
		vector<float> result(n);
		for (int i = 0; i < n; i++) {
			result[i] = Float64();
		}
		return result;
	}
};

// 