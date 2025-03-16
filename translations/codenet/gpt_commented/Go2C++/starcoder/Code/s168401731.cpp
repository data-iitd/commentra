#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cctype>
#include <ctime>
#include <csignal>
#include <csetjmp>
#include <cstdarg>
#include <cerrno>
#include <clocale>
#include <cctype>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cassert>
#include <cfloat>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
using namespace std;

// getScanner initializes a new scanner for the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer size.
static istream* getScanner(FILE* fp) {
	istream* scanner = new istream(fp);
	scanner->imbue(locale(""));
	scanner->word_token();
	scanner->rdbuf()->pubsetbuf(new char[500001], 500000);
	return scanner;
}

// getNextString retrieves the next string from the scanner.
static string getNextString(istream* scanner) {
	scanner->ignore();
	string s;
	*scanner >> s;
	return s;
}

// getNextInt converts the next string from the scanner to an integer.
static int getNextInt(istream* scanner) {
	int i;
	*scanner >> i;
	return i;
}

// getNextInt64 converts the next string from the scanner to a 64-bit integer.
static int64_t getNextInt64(istream* scanner) {
	int64_t i;
	*scanner >> i;
	return i;
}

// getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
static uint64_t getNextUint64(istream* scanner) {
	uint64_t i;
	*scanner >> i;
	return i;
}

// getNextFloat64 converts the next string from the scanner to a float64.
static double getNextFloat64(istream* scanner) {
	double i;
	*scanner >> i;
	return i;
}

int main() {
	// Initialize file pointers for input and output.
	FILE* fp = stdin;
	FILE* wfp = stdout;

	// Check for command line arguments to open input and output files.
	if (argc > 1) {
		fp = fopen(argv[1], "r"); // Open input file if provided.
		if (argc > 2) {
			wfp = fopen(argv[2], "w"); // Create output file if provided.
		}
	}

	// Create a scanner for reading input and a writer for output.
	istream* scanner = getScanner(fp);
	ostream* writer = new ostream(wfp);

	// Read the number of integers to process.
	int n = getNextInt(scanner);

	// Initialize the answer as "second" and check for odd integers.
	string ans = "second";
	for (int i = 0; i < n; i++) {
		int a = getNextInt(scanner); // Read the next integer.
		if (a % 2 == 1) { // Check if the integer is odd.
			ans = "first"; // If odd, set answer to "first".
			break; // Exit the loop early if an odd integer is found.
		}
	}

	// Write the result to the output.
	*writer << ans << endl;
	delete writer; // Ensure all buffered data is written to the output.
	return 0;
}

