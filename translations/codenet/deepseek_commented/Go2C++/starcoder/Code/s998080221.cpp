#include <bits/stdc++.h>

using namespace std;

// bufReader is a struct to efficiently read input.
struct bufReader {
	std::istream *r;
	std::vector<char> buf;
	int i;
	bufReader() {
		r = &cin;
		i = 0;
	}
	bufReader(std::istream &stream) {
		r = &stream;
		i = 0;
	}
	void readLine() {
		if (i < (int)buf.size()) {
			return;
		}
		buf.clear();
		i = 0;
		std::string s;
		std::getline(*r, s);
		buf = std::vector<char>(s.begin(), s.end());
	}
	std::string next() {
		readLine();
		std::string s;
		while (i < (int)buf.size() && buf[i] =='') {
			i++;
		}
		while (i < (int)buf.size() && buf[i]!='') {
			s += buf[i++];
		}
		while (i < (int)buf.size() && buf[i] =='') {
			i++;
		}
		return s;
	}
	std::string nextLine() {
		std::string s;
		std::getline(*r, s);
		return s;
	}
	int nextInt() {
		int x;
		std::stringstream ss;
		ss << next();
		ss >> x;
		return x;
	}
	long long nextInt64() {
		long long x;
		std::stringstream ss;
		ss << next();
		ss >> x;
		return x;
	}
};

// Initialize global reader and writer for input and output operations.
bufReader reader;
std::ostream *writer = &cout;

// next is a wrapper for reader.next().
std::string next() {
	return reader.next();
}

// nextInt64 reads the next token as an int64.
long long nextInt64() {
	return reader.nextInt64();
}

// nextInt reads the next token as an int.
int nextInt() {
	return reader.nextInt();
}

// nextLine is a wrapper for reader.nextLine().
std::string nextLine() {
	return reader.nextLine();
}

// out prints the arguments to the output.
void out(std::initializer_list<std::string> a) {
	for (auto &x : a) {
		*writer << x;
	}
	*writer << "\n";
}

// max64 returns the maximum of two int64 values.
long long max64(long long x, long long y) {
	return (x > y)? x : y;
}

// max returns the maximum of two int values.
int max(int x, int y) {
	return (x > y)? x : y;
}

// min64 returns the minimum of two int64 values.
long long min64(long long x, long long y) {
	return (x < y)? x : y;
}

// min returns the minimum of two int values.
int min(int x, int y) {
	return (x < y)? x : y;
}

// abs64 returns the absolute value of an int64.
long long abs64(long long x) {
	return (x < 0)? -x : x;
}

// abs returns the absolute value of an int.
int abs(int x) {
	return (x < 0)? -x : x;
}

// joinInt64s joins an array of int64 values into a string with a separator.
std::string joinInt64s(std::vector<long long> a, std::string sep) {
	std::string s = "";
	for (int i = 0; i < (int)a.size(); i++) {
		s += std::to_string(a[i]);
		if (i < (int)a.size() - 1) {
			s += sep;
		}
	}
	return s;
}

// joinInts joins an array of int values into a string with a separator.
std::string joinInts(std::vector<int> a, std::string sep) {
	std::string s = "";
	for (int i = 0; i < (int)a.size(); i++) {
		s += std::to_string(a[i]);
		if (i < (int)a.size() - 1) {
			s += sep;
		}
	}
	return s;
}

// divUp64 returns the ceiling of the division of x by y.
long long divUp64(long long x, long long y) {
	return (x + y - 1) / y;
}

// divUp returns the ceiling of the division of x by y.
int divUp(int x, int y) {
	return (x + y - 1) / y;
}

// gcd64 returns the greatest common divisor of two int64 values.
long long gcd64(long long x, long long y) {
	if (x < y) {
		x, y = y, x;
	}
	while (y!= 0) {
		x, y = y, x % y;
	}
	return x;
}

// gcd returns the greatest common divisor of two int values.
int gcd(int x, int y) {
	return (int)gcd64(x, y);
}

// lcm64 returns the least common multiple of two int64 values.
long long lcm64(long long x, long long y) {
	return x * y / gcd64(x, y);
}

// lcm returns the least common multiple of two int values.
int lcm(int x, int y) {
	return (int)lcm64(x, y);
}

// pow64 returns the result of raising x to the power of y.
long long pow64(long long x, long long y) {
	return (long long)pow(x, y);
}

// pow returns the result of raising x to the power of y.
int pow(int x, int y) {
	return (int)pow64(x, y);
}

// main function calls solve and flushes the writer at the end.
int main() {
	solve();
	return 0;
}

// solve function implements the main logic of the program.
void solve() {
	int N, _;
	std::cin >> N >> _;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	int maxProfit = 0;
	int maxCnt = 0;
	int maxA = A[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		int profit = max(0, maxA - A[i]);
		if (maxProfit < profit) {
			maxProfit = profit;
			maxCnt = 1;
		} else if (maxProfit == profit) {
			maxCnt++;
		}
		maxA = max(maxA, A[i]);
	}
	std::cout << maxCnt << "\n";
}

