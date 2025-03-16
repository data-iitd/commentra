
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
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <climits>
#include <cfloat>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>
#include <limits>
#include <utility>
#include <valarray>
#include <functional>
#include <numeric>
#include <bitset>
#include <deque>
#include <fstream>
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
#include <vector>
#include <cassert>
#include <climits>
#include <cfloat>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>
#include <limits>
#include <utility>
#include <valarray>
#include <functional>
#include <numeric>
#include <bitset>
#include <deque>
#include <fstream>
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
#include <vector>

using namespace std;

// getScanner initializes and returns a new bufio.Scanner from the given file pointer
static bufio::Scanner getScanner(FILE *fp) {
	bufio::Scanner scanner(fp);
	scanner.Split(bufio::ScanWords);
	scanner.Buffer(make([]byte, 500001), 500000); // buffer size
	return scanner;
}

// getNextString reads and returns the next word as a string from the scanner
static string getNextString(bufio::Scanner &scanner) {
	scanner.Scan();
	return scanner.Text();
}

// getNextInt reads and converts the next integer from the scanner to an int
static int getNextInt(bufio::Scanner &scanner) {
	int i;
	sscanf(getNextString(scanner).c_str(), "%d", &i);
	return i;
}

// getNextInt64 reads and converts the next integer from the scanner to an int64
static int64_t getNextInt64(bufio::Scanner &scanner) {
	int64_t i;
	sscanf(getNextString(scanner).c_str(), "%lld", &i);
	return i;
}

// getNextUint64 reads and converts the next unsigned integer from the scanner to a uint64
static uint64_t getNextUint64(bufio::Scanner &scanner) {
	uint64_t i;
	sscanf(getNextString(scanner).c_str(), "%llu", &i);
	return i;
}

// getNextFloat64 reads and converts the next floating-point number from the scanner to a float64
static float64_t getNextFloat64(bufio::Scanner &scanner) {
	float64_t i;
	sscanf(getNextString(scanner).c_str(), "%lf", &i);
	return i;
}

// main function is the entry point of the program
int main() {
	// open standard input as default file if no arguments are provided
	FILE *fp = stdin;
	// open output file if provided as an argument
	FILE *wfp = stdout;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
		// create output file if provided as an argument
		if (argc > 2) {
			wfp = fopen(argv[2], "w");
		}
	}

	// initialize scanner and writer
	bufio::Scanner scanner = getScanner(fp);
	bufio::Writer writer = bufio::Writer(wfp);

	// read the first integer from the input
	int n = getNextInt(scanner);

	// initialize answer variable
	string ans = "second";
	// iterate through the input integers
	for (int i = 0; i < n; i++) {
		// read the next integer from the input
		int a = getNextInt(scanner);
		// check if the current integer is odd
		if (a % 2 == 1) {
			// update the answer if an odd integer is found
			ans = "first";
			// exit the loop if only one odd integer is found
			break;
		}
	}
	// write the answer to the output
	fprintf(wfp, "%s\n", ans.c_str());
	// flush the writer buffer
	writer.Flush();

	return 0;
}

