

// by syu
#include <bits/stdc++.h>
using namespace std;

// Define a new Scanner type
struct Scanner {
	Scanner(std::istream& in, int max = 1048576) : buf(max), s(in, &buf) {}
	string next() {
		s.read(buf.data(), buf.size());
		s.ignore(numeric_limits<streamsize>::max(), '\n');
		return s.str();
	}
	int nextInt() {
		int x;
		sscanf(next().c_str(), "%d", &x);
		return x;
	}
private:
	string buf;
	stringstream s;
};

int main() {
	// Read the first two integers from the standard input
	Scanner in(cin);
	int n = in.nextInt(), k = in.nextInt();

	// Check if n is divisible by k
	if (n % k == 0) {
		// If it is, print 0
		cout << 0 << endl;
	} else {
		// If not, print 1
		cout << 1 << endl;
	}
}

// Print a line with the given arguments
void Pln() {
	cout << endl;
}
void Pln(int x) {
	cout << x << endl;
}
void Pln(long long x) {
	cout << x << endl;
}
void Pln(double x) {
	cout << x << endl;
}
void Pln(const string& s) {
	cout << s << endl;
}
void Pln(const char* s) {
	cout << s << endl;
}
template <typename T, typename... Args>
void Pln(const T& t, const Args&... args) {
	cout << t;
	Pln(args...);
}



