#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Function to read a line from standard input
string readLine() {
	string line;
	getline(cin, line);
	return line;
}

// Function to get the next token from the input
string next() {
	static string buffer;
	static int index = 0;
	if (index >= buffer.size()) {
		buffer = readLine();
		index = 0;
	}
	int start = index;
	while (index < buffer.size() && buffer[index] != ' ') {
		index++;
	}
	string token = buffer.substr(start, index - start);
	index++;
	return token;
}

// Function to get the next line from the input
string nextLine() {
	static string buffer;
	static int index = 0;
	if (index >= buffer.size()) {
		buffer = readLine();
		index = 0;
	}
	int start = index;
	while (index < buffer.size() && buffer[index] != '\n') {
		index++;
	}
	string line = buffer.substr(start, index - start);
	index++;
	return line;
}

// Function to print output
void out(const vector<int64_t>& a) {
	for (int64_t i : a) {
		cout << i << " ";
	}
	cout << endl;
}

// Function to get the next token and convert it to an int64_t
int64_t nextInt() {
	return stoll(next());
}

// Function to get the next line and convert it to an int64_t
vector<int64_t> nextInts() {
	string line = nextLine();
	vector<int64_t> numbers;
	stringstream ss(line);
	int64_t num;
	while (ss >> num) {
		numbers.push_back(num);
	}
	return numbers;
}

// Function to compute the maximum of two int64_t values
int64_t max(int64_t x, int64_t y) {
	return x > y ? x : y;
}

// Function to compute the minimum of two int64_t values
int64_t min(int64_t x, int64_t y) {
	return x < y ? x : y;
}

// Function to join a vector of int64_t into a string with a separator
string joinInts(const vector<int64_t>& a, const string& sep) {
	string result;
	for (size_t i = 0; i < a.size(); ++i) {
		result += to_string(a[i]);
		if (i < a.size() - 1) {
			result += sep;
		}
	}
	return result;
}

// Function to perform ceiling division of x by y
int64_t divUp(int64_t x, int64_t y) {
	return (x + y - 1) / y;
}

// Main function where the program execution starts
void solve() {
	int64_t N = nextInt();
	vector<int64_t> T(N), A(N);
	for (int64_t i = 0; i < N; i++) {
		T[i] = nextInt();
		A[i] = nextInt();
	}
	int64_t t = T[0], a = A[0];
	for (int64_t i = 1; i < N; i++) {
		int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
		t = T[i] * r;
		a = A[i] * r;
	}
	cout << t + a << endl;
}

int main() {
	solve();
	return 0;
}
