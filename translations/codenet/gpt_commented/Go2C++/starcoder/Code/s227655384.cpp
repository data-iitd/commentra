#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

// ReadLongLines reads a specified number of long lines from standard input.
std::vector<std::string> ReadLongLines(int times) {
	std::vector<std::string> result(times); // Create a slice to hold the lines read
	std::cin.tie(0); // Set cin to not use buffering
	std::cin.sync_with_stdio(0); // Set cin to not synchronize with C++ streams
	std::istream_iterator<std::string> input_iterator(std::cin); // Create an input iterator for cin
	std::istream_iterator<std::string> end_iterator; // Create an end iterator for cin
	std::copy(input_iterator, end_iterator, result.begin()); // Copy the lines from cin to the result slice
	return result; // Return the lines read
}

// Console struct for handling output
struct Console {
	std::ostream* writer; // Pointer to the output stream
};

// NewConsole initializes a new Console instance
Console NewConsole() {
	return Console{&std::cout}; // Create a new output stream for cout
}

// Printf formats and writes output to the console
void Printf(Console& con, const char* format,...) {
	va_list args; // Declare a variable argument list
	va_start(args, format); // Initialize the argument list
	std::vfprintf(con.writer, format, args); // Format and write to the output stream
	va_end(args); // End the argument list
}

// Println writes a string followed by a newline to the console
void Println(Console& con, const std::string& s) {
	std::fprintf(con.writer, "%s\n", s.c_str()); // Write the string to the output stream
}

// Close does nothing
void Close(Console& con) {
}

// Flush does nothing
void Flush(Console& con) {
}

// PrintList prints a list of integers to the console
void PrintList(const std::vector<int>& list) {
	Console con = NewConsole(); // Create a new console instance
	for (int i = 0; i < list.size(); i++) {
		if (i == 0) {
			Printf(con, "%d", list[i]); // Print the first element without a leading space
		} else {
			Printf(con, " %d", list[i]); // Print subsequent elements with a leading space
		}
	}
	Println(con, ""); // Print a newline after the list
}

// main function where the program execution begins
int main() {
	std::map<int, int> m; // Create a map to track unique integers
	std::vector<std::string> lines = ReadLongLines(4); // Read 4 lines from input
	std::vector<std::string> a = Split(lines[1], " "); // Split the second line into individual strings

	// Convert strings to integers and store them in the map
	for (int i = 0; i < a.size(); i++) {
		int n = std::stoi(a[i]); // Convert string to integer
		m[n] = 1; // Add the integer to the map
	}

	std::vector<int> result; // Slice to hold the result integers
	std::vector<std::string> b = Split(lines[3], " "); // Split the fourth line into individual strings

	// Process the integers from the fourth line
	for (int i = 0; i < b.size(); i++) {
		int n = std::stoi(b[i]); // Convert string to integer
		if (m.find(n)!= m.end()) { // Check if the integer exists in the map
			m.erase(n); // Remove it from the map if it exists
		} else {
			m[n] = 1; // Add it to the map if it does not exist
		}
	}

	// Collect remaining integers from the map into the result slice
	for (std::map<int, int>::iterator it = m.begin(); it!= m.end(); it++) {
		result.push_back(it->first); // Append the key to the result slice
	}

	// Sort the result slice in ascending order
	std::sort(result.begin(), result.end());

	// Print the sorted result
	for (int j = 0; j < result.size(); j++) {
		Printf(NewConsole(), "%d\n", result[j]); // Print each integer in the result
	}
}

