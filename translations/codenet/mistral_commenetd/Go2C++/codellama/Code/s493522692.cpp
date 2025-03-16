
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// Util functions
string nextStr() {
	string s;
	cin >> s;
	return s;
}

int nextInt() {
	int i;
	cin >> i;
	return i;
}

int maxInt(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int minInt(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

int absInt(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

double absFloat64(double a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

double maxFloat64(double a, double b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

double minFloat64(double a, double b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

int str2Int(string s) {
	int n;
	stringstream ss(s);
	ss >> n;
	return n;
}

string reverse(string s) {
	string r = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		r += s[i];
	}
	return r;
}

int powInt(int p, int q) {
	return int(pow(p, q));
}

bool isPrime(int x) {
	if (x == 1) {
		return false;
	}
	if (x == 2) {
		return true;
	}
	if (x % 2 == 0) {
		return false;
	}

	int rootx = int(sqrt(x));
	int i = 3;
	bool b = true;
	for (i = 3; i <= rootx; i = i + 2) {
		if (x % i == 0) {
			b = false;
			break;
		}
	}
	return b;
}

vector<int> PrimeFactors(int n) {
	vector<int> pfs;
	while (n % 2 == 0) {
		pfs.push_back(2);
		n = n / 2;
	}

	for (int i = 3; i * i <= n; i = i + 2) {
		while (n % i == 0) {
			pfs.push_back(i);
			n = n / i;
		}
	}

	if (n > 2) {
		pfs.push_back(n);
	}

	return pfs;
}

map<int, int> PrimeFactorsMap(int n) {
	map<int, int> pfs;
	while (n % 2 == 0) {
		pfs[2]++;
		n = n / 2;
	}

	for (int i = 3; i * i <= n; i = i + 2) {
		while (n % i == 0) {
			pfs[i]++;
			n = n / i;
		}
	}

	if (n > 2) {
		pfs[n]++;
	}

	return pfs;
}

// Main function
int main() {
	// Util functions
	string s = nextStr();
	int i = nextInt();
	int a = maxInt(i, i + 1);
	int b = minInt(i, i + 1);
	int c = absInt(i);
	double d = absFloat64(i);
	double e = maxFloat64(i, i + 1);
	double f = minFloat64(i, i + 1);
	int g = str2Int(s);
	string h = reverse(s);
	int j = powInt(i, i + 1);
	bool k = isPrime(i);
	vector<int> l = PrimeFactors(i);
	map<int, int> m = PrimeFactorsMap(i);

	// Main function
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	cout << sum << endl;

	// End of code
	return 0;
}

