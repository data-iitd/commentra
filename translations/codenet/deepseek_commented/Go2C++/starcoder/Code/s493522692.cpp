#include <bits/stdc++.h>

using namespace std;

// Utility Functions

// Reads the next input as a string
string nextStr() {
	string s;
	getline(cin, s);
	return s;
}

// Reads the next input as an integer
int nextInt() {
	int n;
	cin >> n;
	return n;
}

// Returns the maximum of two integers
int maxInt(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// Returns the minimum of two integers
int minInt(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// Returns the absolute value of an integer
int absInt(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// Returns the absolute value of a float64
float64 absFloat64(float64 a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// Returns the maximum of two float64 values
float64 maxFloat64(float64 a, float64 b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// Returns the minimum of two float64 values
float64 minFloat64(float64 a, float64 b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// Converts a string to an integer
int str2Int(string s) {
	int n;
	stringstream ss;
	ss << s;
	ss >> n;
	return n;
}

// Reverses a string
string reverse(string s) {
	string r = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		r += s[i];
	}
	return r;
}

// Raises an integer to the power of another integer
int powInt(int p, int q) {
	return int(pow(p, q));
}

// Checks if a number is prime
bool isPrime(int x) {
	if (x == 1) {
		return false;
	}
	if (x == 2) {
		return true;
	}
	if (x%2 == 0) {
		return false;
	}

	bool b = true;
	int rootx = int(sqrt(x));
	int i = 3;
	for (i = 3; i <= rootx; i += 2) {
		if (x%i == 0) {
			b = false;
			break;
		}
	}
	return b;
}

// Returns the prime factors of a number
vector<int> PrimeFactors(int n) {
	// Get the number of 2s that divide n
	vector<int> pfs;
	while (n%2 == 0) {
		pfs.push_back(2);
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			pfs.push_back(i);
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		pfs.push_back(n);
	}

	return pfs;
}

// Returns the prime factors of a number as a map
map<int, int> PrimeFactorsMap(int n) {
	map<int, int> pfs;
	// Get the number of 2s that divide n
	while (n%2 == 0) {
		if (pfs.find(2)!= pfs.end()) {
			pfs[2]++;
		} else {
			pfs[2] = 1;
		}
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			if (pfs.find(i)!= pfs.end()) {
				pfs[i]++;
			} else {
				pfs[i] = 1;
			}
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		if (pfs.find(n)!= pfs.end()) {
			pfs[n]++;
		} else {
			pfs[n] = 1;
		}
	}

	return pfs;
}

// Sums up a slice of integers
int sumInts(vector<int> x) {
	int total = 0;
	for (int i = 0; i < x.size(); i++) {
		total += x[i];
	}
	return total;
}

// Computes the greatest common divisor of two integers
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

// Computes the least common multiple of two integers
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

// Constants and Variables

const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Main Function
int main() {
	// 'S'がN個、'c'がM個
	int N, M;
	cin >> N >> M;
	int tmp = minInt(N, M/2);
	int ans = 0;
	ans += tmp;
	N -= tmp;
	M -= tmp * 2;
	//cout << ans << " " << N << " " << M << endl;
	cout << ans + M/4 << endl;
}

