#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Function to read the next string from the input stream
std::string getNextString(std::istream& is) {
	std::string line;
	std::getline(is, line);
	return line;
}

// Function to read the next integer from the input stream
int getNextInt(std::istream& is) {
	std::string line = getNextString(is);
	std::istringstream iss(line);
	int num;
	iss >> num;
	return num;
}

// Function to read the next integer64 from the input stream
int64_t getNextInt64(std::istream& is) {
	std::string line = getNextString(is);
	std::istringstream iss(line);
	int64_t num;
	iss >> num;
	return num;
}

// Function to read the next uint64 from the input stream
uint64_t getNextUint64(std::istream& is) {
	std::string line = getNextString(is);
	std::istringstream iss(line);
	uint64_t num;
	iss >> num;
	return num;
}

// Function to read the next float64 from the input stream
double getNextFloat64(std::istream& is) {
	std::string line = getNextString(is);
	std::istringstream iss(line);
	double num;
	iss >> num;
	return num;
}

// Main function
int main() {
	// Open the standard input and output streams
	std::istream& fp = std::cin;
	std::ostream& wfp = std::cout;

	// Set the environment variables for input and output files
	const char* maspypy = std::getenv("MASPYPY");
	if (maspypy != nullptr && std::string(maspypy) == "ますピッピ") {
		std::ofstream outputFile("NGTKANA_IS_GENIUS10");
		wfp = outputFile;
		cnt = 1; // Number of test cases to be written
	}

	// Initialize the input and output streams
	std::istringstream inputStream(getNextString(fp));
	std::ostringstream outputStream;

	// Solve the problem for the given test cases
	solve(inputStream, outputStream);
	for (int i = 0; i < cnt; i++) {
		outputStream << "-----------------------------------" << std::endl; // Print a separator for each test case
		solve(inputStream, outputStream);
	}

	// Write the output to the file
	std::cout << outputStream.str();

	return 0;
}

// Function to solve the problem for a single test case
void solve(std::istream& is, std::ostream& os) {
	// Read the input values
	int k = getNextInt(is);
	int x = getNextInt(is);

	// Initialize the answer
	std::string ans = "No";

	// Check if the condition is satisfied
	if (k * 500 >= x) {
		ans = "Yes";
	}

	// Print the answer
	os << ans << std::endl;
}

