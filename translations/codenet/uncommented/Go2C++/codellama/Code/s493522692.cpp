
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

//Util
string nextStr() {
	string s;
	cin >> s;
	return s;
}

int nextInt() {
	int n;
	cin >> n;
	return n;
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
	n = atoi(s.c_str());
	return n;
}

string reverse(string s) {
	string r;
	for (int i = s.length() - 1; i >= 0; i--) {
		r += s[i];
	}
	return r;
}

int powInt(int p, int q) {
	return (int)pow(p, q);
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

	bool b = true;
	int rootx = (int)sqrt(x);
	int i = 3;
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
	// Get the number of 2s that divide n
	while (n % 2 == 0) {
		pfs.push_back(2);
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n % i == 0) {
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

map<int, int> PrimeFactorsMap(int n) {
	map<int, int> pfs;
	// Get the number of 2s that divide n
	while (n % 2 == 0) {
		if (pfs.find(2) != pfs.end()) {
			pfs[2]++;
		} else {
			pfs[2] = 1;
		}
		//pfs = append(pfs, 2)
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n % i == 0) {
			if (pfs.find(i) != pfs.end()) {
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
		if (pfs.find(n) != pfs.end()) {
			pfs[n]++;
		} else {
			pfs[n] = 1;
		}
	}

	return pfs;
}

int sumInts(vector<int> x) {

	int total = 0;
	for (int i = 0; i < x.size(); i++) {
		total += x[i];
	}

	return total;
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int lcm(int x, int y) {

	return x * y / gcd(x, y);

}

//Main
int main() {
	// 'S'がN個、'c'がM個
	int N, M;
	cin >> N >> M;
	int tmp = minInt(N, M / 2);
	int ans = 0;
	ans += tmp;
	N -= tmp;
	M -= tmp * 2;
	//fmt.Println(ans, N, M)
	cout << ans + M / 4 << endl;
	return 0;
}

