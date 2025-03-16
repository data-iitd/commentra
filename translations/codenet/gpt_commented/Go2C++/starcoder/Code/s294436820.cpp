#include <bits/stdc++.h>
using namespace std;

// IO helper functions

// nextToken and nextLine are function variables that will be initialized 
// by SetInput() and SetUnbufferedInput() for reading input tokens and lines.
auto nextToken = []() -> string {
	string s;
	cin >> s;
	return s;
}

auto nextLine = []() -> string {
	string s;
	getline(cin, s);
	return s;
}

// OutputBuffer holds a buffered writer for output. It must be initialized by SetOutput().
auto OutputBuffer = new ofstream();

// OutputWriter holds an io.Writer for output. It must be initialized by SetOutput().
auto OutputWriter = new ofstream(OutputBuffer);

// SetInteractive configures the IO functions for interactive input/output.
void SetInteractive(istream& is, ostream& os) {
	InputReader = &is;
	OutputWriter = &os;
}

// Setup OutputBuffer and OutputWriter for buffered output.
void SetOutput(ostream& os) {
	OutputBuffer = new ofstream();
	OutputWriter = &os;
}

// Flushes OutputBuffer to ensure all buffered data is written out.
void Flush() {
	if (OutputBuffer) {
		OutputBuffer->flush();
	}
}

// IsSpace checks if a byte is a whitespace character.
bool IsSpace(char c) {
	return c =='' || c == '\n' || c == '\r' || c == '\t' || c == -1;
}

// IsNewLine checks if a byte is a newline character.
bool IsNewLine(char c) {
	return c == '\n' || c == '\r';
}

// SetInput initializes the nextToken function with an input buffer.
void SetInput(istream& is) {
	InputReader = &is;
	nextToken = []() -> string {
		string s;
		getline(*InputReader, s);
		return s;
	};
}

// SetUnbufferedInput configures the nextToken function for unbuffered input.
void SetUnbufferedInput(istream& is) {
	InputReader = &is;
	nextToken = []() -> string {
		string s;
		cin >> s;
		return s;
	};
}

// IO functions

// readb reads the next token and returns it as a byte slice.
string readb() {
	string s = nextToken();
	return s;
}

// reads reads the next token and returns it as a string.
string reads() {
	string s = nextToken();
	return s;
}

// readbln reads the next line as a byte slice, excluding the trailing newline.
string readbln() {
	string s;
	getline(*InputReader, s);
	return s;
}

// readsln reads the next line and returns it as a string.
string readsln() {
	string s;
	getline(*InputReader, s);
	return s;
}

// readll reads the next token and returns it as an int64.
int64_t readll() {
	return stoll(nextToken());
}

// readi reads the next token and returns it as an int.
int readi() {
	return stoi(nextToken());
}

// readf reads the next token and returns it as a float64.
double readf() {
	return stod(nextToken());
}

// printf writes formatted output to OutputWriter.
void printf(const char* format,...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

// println writes output to OutputWriter without formatting.
void println(const char* s) {
	printf("%s\n", s);
}

// eprintf writes formatted output to stderr.
void eprintf(const char* format,...) {
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
}

// eprintln writes output to stderr without formatting.
void eprintln(const char* s) {
	eprintf("%s\n", s);
}

// debugf writes formatted debug output to stderr if DEBUG is enabled.
void debugf(const char* format,...) {
	if (!DEBUG) {
		return;
	}
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
}

// debug writes debug output to stderr if DEBUG is enabled.
void debug(const char* s) {
	if (!DEBUG) {
		return;
	}
	printf("%s\n", s);
}

// -----------------------------------------------------------------------------

// Utilities

// sumSlice calculates the sum of a slice of integers.
int sumSlice(vector<int> a) {
	int res = 0;
	for (int v : a) {
		res += v;
	}
	return res;
}

// sumSlicell calculates the sum of a slice of int64.
int64_t sumSlicell(vector<int64_t> a) {
	int64_t res = 0;
	for (int64_t v : a) {
		res += v;
	}
	return res;
}

// readInts reads N integers from input and returns the count and the slice.
pair<int, vector<int>> readInts(int N) {
	if (N == 0) {
		N = readi();
	}
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		a[i] = readi();
	}
	return {N, a};
}

// readIntsll reads N int64 values from input and returns the count and the slice.
pair<int, vector<int64_t>> readIntsll(int N) {
	if (N == 0) {
		N = readi();
	}
	vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		a[i] = readll();
	}
	return {N, a};
}

// -----------------------------------------------------------------------------

// Simple math functions

const int INF = 1000000007;
const int INF2 = 1000000009;
const int INF3 = 998244353;

// min returns the smaller of two integers.
int min(int a, int b) {
	return a < b? a : b;
}

// minll returns the smaller of two int64 values.
int64_t minll(int64_t a, int64_t b) {
	return a < b? a : b;
}

// minf returns the smaller of two float64 values.
double minf(double a, double b) {
	return a < b? a : b;
}

// max returns the larger of two integers.
int max(int a, int b) {
	return a > b? a : b;
}

// maxll returns the larger of two int64 values.
int64_t maxll(int64_t a, int64_t b) {
	return a > b? a : b;
}

// maxf returns the larger of two float64 values.
double maxf(double a, double b) {
	return a > b? a : b;
}

// abs returns the absolute value of an integer.
int abs(int a) {
	return a < 0? -a : a;
}

// absll returns the absolute value of an int64.
int64_t absll(int64_t a) {
	return a < 0? -a : a;
}

// absf returns the absolute value of a float64.
double absf(double a) {
	return a < 0? -a : a;
}

// egcd computes the extended GCD of a and b, returning d, x, y.
pair<int, int, int> egcd(int a, int b) {
	if (b == 0) {
		return {a, 1, 0};
	}
	auto [d, x, y] = egcd(b, a % b);
	return {d, y, x - a / b * y};
}

// egcdll computes the extended GCD of a and b for int64 values.
pair<int64_t, int64_t, int64_t> egcdll(int64_t a, int64_t b) {
	if (b == 0) {
		return {a, 1, 0};
	}
	auto [d, x, y] = egcdll(b, a % b);
	return {d, y, x - a / b * y};
}

// gcd computes the GCD of a and b.
int gcd(int a, int b) {
	return egcd(a, b).first;
}

// gcdll computes the GCD of a and b for int64 values.
int64_t gcdll(int64_t a, int64_t b) {
	return egcdll(a, b).first;
}

// set up IO functions
void init() {
	// Initialize input and output for non-interactive mode
	SetInput(cin);
	SetOutput(cout);

	// Uncomment below to enable interactive mode
	// SetInteractive(cin, cout);
}

// main function to execute the program logic
int main() {
	defer Flush(); // Ensure output is flushed at the end
	int h, w, k = readi(), readi(), readi();
	vector<vector<int>> m(h);
	for (int i = 0; i < h; i++) {
		m[i] = readInts(w);
	}

	int answer = solve(h, w, k, m);
	printf("%d\n", answer);
}

const int Black = 35; // Define a constant for the black color

// countBlack counts the number of black cells in the grid.
int countBlack(int h, int w, vector<vector<int>> m) {
	int count = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (m[i][j] == Black) {
				count++;
			}
		}
	}
	return count;
}

// solve calculates the number of ways to paint the grid to achieve the target count of black cells.
int solve(int h, int w, int a, vector<vector<int>> m) {
	int result = 0;
	for (int i = 0; i < 1 << h; i++) {
		for (int k = 0; k < 1 << w; k++) {
			vector<vector<int>> tmp(h);
			for (int j = 0; j < h; j++) {
				tmp[j] = m[j];
			}
			// Paint rows based on the current combination
			for (int j = 0; j < h; j++) {
				int hPainted = (1 << j & i);
				if (hPainted > 0) {
					for (int l = 0; l < w; l++) {
						tmp[j][l] = 1;
					}
				}
			}
			// Paint columns based on the current combination
			for (int j = 0; j < w; j++) {
				int wPainted = (1 << j & k);
				if (wPainted > 0) {
					for (int l = 0; l < h; l++) {
						tmp[l][j] = 1;
					}
				}
			}
			if (countBlack(h, w, tmp) == a) {
				result++;
			}
		}
	}
	return result;
}

