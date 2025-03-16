#include <bits/stdc++.h>

using namespace std;

// getScanner initializes a new scanner to read input from a file.
// It sets the split function to scan words and buffers the input to a specified size.
auto getScanner(FILE *fp) {
	auto scanner = make_shared<stringstream>();
	auto ss = make_shared<istream>(fp);
	scanner->rdbuf(ss->rdbuf());
	return make_shared<istream_iterator<string>>(*scanner), make_shared<istream_iterator<string>>();
}

// getNextString reads the next token from the scanner and returns it as a string.
string getNextString(istream_iterator<string> &iter, istream_iterator<string> &end) {
	iter++;
	return *iter++;
}

// getNextInt reads the next token, converts it to an integer, and returns it.
int getNextInt(istream_iterator<string> &iter, istream_iterator<string> &end) {
	return stoi(getNextString(iter, end));
}

// getNextInt64 reads the next token, converts it to an int64, and returns it.
int64_t getNextInt64(istream_iterator<string> &iter, istream_iterator<string> &end) {
	return stoll(getNextString(iter, end));
}

// getNextUint64 reads the next token, converts it to a uint64, and returns it.
uint64_t getNextUint64(istream_iterator<string> &iter, istream_iterator<string> &end) {
	return stoull(getNextString(iter, end));
}

// getNextFloat64 reads the next token, converts it to a float64, and returns it.
double getNextFloat64(istream_iterator<string> &iter, istream_iterator<string> &end) {
	return stod(getNextString(iter, end));
}

// main function handles the program's flow.
// It sets up the input and output files based on environment variables,
// calls the solve function, and prints separators if necessary.
int main() {
	auto fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
	auto wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	auto cnt = 0;

	if (getenv("MASPY") == "ますピ") {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
		cnt = 2;
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	auto scanner = getScanner(fp);
	auto writer = make_shared<ostream>(wfp);
	solve(scanner, writer);
	for (int i = 0; i < cnt; i++) {
		*writer << "-----------------------------------" << endl;
		solve(scanner, writer);
	}
	return 0;
}

// solve function reads two integers k and x, and determines if k * 500 is greater than or equal to x.
// It writes "Yes" or "No" based on this condition.
void solve(istream_iterator<string> &iter, istream_iterator<string> &end, ostream_iterator<string> &out) {
	auto k = getNextInt(iter, end);
	auto x = getNextInt(iter, end);

	auto ans = "No";
	if (k*500 >= x) {
		ans = "Yes";
	}
	*out++ = ans;
	*out++ = endl;
}

