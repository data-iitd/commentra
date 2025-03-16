#include <bits/stdc++.h>

using namespace std;

// getScanner initializes a new bufio.Scanner with specific configurations.
auto getScanner(FILE *fp) {
	return make_unique<bufio::Scanner>(fp);
}

// getNextString reads the next word from the scanner.
auto getNextString(bufio::Scanner *scanner) {
	scanner->Scan();
	return scanner->Text();
}

// getNextInt reads the next word, converts it to an integer, and returns it.
auto getNextInt(bufio::Scanner *scanner) {
	return atoi(getNextString(scanner).c_str());
}

// getNextInt64 reads the next word, converts it to an int64, and returns it.
auto getNextInt64(bufio::Scanner *scanner) {
	return atoll(getNextString(scanner).c_str());
}

// getNextUint64 reads the next word, converts it to a uint64, and returns it.
auto getNextUint64(bufio::Scanner *scanner) {
	return atoll(getNextString(scanner).c_str());
}

// getNextFloat64 reads the next word, converts it to a float64, and returns it.
auto getNextFloat64(bufio::Scanner *scanner) {
	return atof(getNextString(scanner).c_str());
}

// Main function handles file input/output operations based on command-line arguments.
int main() {
	auto fp = fopen(getenv("INPUT_PATH"), "r");
	auto wfp = fopen(getenv("OUTPUT_PATH"), "w");

	// Check if command-line arguments are provided for file input/output.
	if (!fp) {
		fp = stdin;
	}
	if (!wfp) {
		wfp = stdout;
	}

	auto scanner = getScanner(fp);
	auto writer = make_unique<bufio::Writer>(wfp);

	// Read the number of integers to process.
	auto n = getNextInt(scanner);

	// Initialize the answer to "second".
	auto ans = "second";
	for (auto i = 0; i < n; i++) {
		auto a = getNextInt(scanner);
		if (a % 2 == 1) {
			ans = "first";
			break;
		}
	}
	// Print the result based on the condition.
	fprintf(wfp, "%s\n", ans.c_str());
	writer->Flush();
}

