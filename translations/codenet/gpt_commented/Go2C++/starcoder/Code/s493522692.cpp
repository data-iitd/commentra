#include <bits/stdc++.h>

using namespace std;

// Utility functions for input and mathematical operations

// nextStr reads the next string from input
string nextStr() {
	string s;
	getline(cin, s);
	return s;
}

// nextInt reads the next integer from input
int nextInt() {
	int n;
	cin >> n;
	return n;
}

// maxInt returns the maximum of two integers
int maxInt(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// minInt returns the minimum of two integers
int minInt(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// absInt returns the absolute value of an integer
int absInt(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// absFloat64 returns the absolute value of a float64
float64 absFloat64(float64 a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// maxFloat64 returns the maximum of two float64 values
float64 maxFloat64(float64 a, float64 b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// minFloat64 returns the minimum of two float64 values
float64 minFloat64(float64 a, float64 b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// str2Int converts a string to an integer
int str2Int(string s) {
	int n;
	istringstream iss(s);
	iss >> n;
	return n;
}

// reverse returns the reversed string
string reverse(string s) {
	string rev = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		rev += s[i];
	}
	return rev;
}

// powInt calculates p raised to the power of q
int powInt(int p, int q) {
	return (int)pow((double)p, (double)q);
}

// isPrime checks if a number is prime
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
	int rootx = (int)sqrt((double)x);
	int i = 3;
	for (i = 3; i <= rootx; i += 2) {
		if (x%i == 0) {
			b = false;
			break;
		}
	}
	return b;
}

// PrimeFactors returns the prime factors of a number
vector<int> PrimeFactors(int n) {
	// Get the number of 2s that divide n
	vector<int> pfs;
	while (n%2 == 0) {
		pfs.push_back(2);
		n = n / 2;
	}

	// n must be odd at this point, so we can skip one element
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			pfs.push_back(i);
			n = n / i;
		}
	}

	// Handle the case when n is a prime number greater than 2
	if (n > 2) {
		pfs.push_back(n);
	}

	return pfs;
}

// PrimeFactorsMap returns a map of prime factors and their counts
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

	// n must be odd at this point, so we can skip one element
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

	// Handle the case when n is a prime number greater than 2
	if (n > 2) {
		if (pfs.find(n)!= pfs.end()) {
			pfs[n]++;
		} else {
			pfs[n] = 1;
		}
	}

	return pfs;
}

// sumInts returns the sum of a slice of integers
int sumInts(vector<int> x) {
	int total = 0;
	for (int i = 0; i < x.size(); i++) {
		total += x[i];
	}
	return total;
}

// gcd calculates the greatest common divisor of two integers
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

// lcm calculates the least common multiple of two integers
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

// Main function
int main() {
	// Read the number of 'S' and 'c'
	int N, M;
	cin >> N >> M;
	int tmp = minInt(N, M/2); // Calculate the minimum of N and half of M
	int ans = 0;
	ans += tmp; // Add the temporary value to the answer
	N -= tmp; // Decrease N by the temporary value
	M -= tmp * 2; // Decrease M by twice the temporary value
	// Output the final answer, which includes the remaining M divided by 4
	cout << ans + M/4 << endl;
	return 0;
}

