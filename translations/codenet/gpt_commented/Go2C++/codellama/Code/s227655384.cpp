
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// ReadLongLines reads a specified number of long lines from standard input.
vector<string> ReadLongLines(int times) {
	vector<string> result(times); // Create a vector to hold the lines read
	string buffer; // Buffer to accumulate line data
	int readBytes = 2; // Initialize readBytes to track the number of bytes read

	// Loop to read the specified number of lines
	for (int i = 0; i < times; i++) {
		while (true) {
			string readBuf; // Read a line from input
			getline(cin, readBuf);
			readBytes += readBuf.length() + 1; // Update the byte count
			buffer += readBuf; // Write the read buffer to the accumulator
			if (readBuf.back() == '\n') { // Check if the line is complete (not a prefix)
				result[i] = buffer; // Store the complete line in the result
				buffer = ""; // Reset the buffer for the next line
				break; // Break out of the inner loop to read the next line
			}
		}
	}
	// Seek back to the previous position to avoid reading ahead
	cin.seekg(-readBytes, ios::cur);
	return result; // Return the lines read
}

// Console struct for handling output
struct Console {
	ostream& writer; // Buffered writer for output

	// Constructor
	Console(ostream& writer) : writer(writer) {}

	// Printf formats and writes output to the console
	void Printf(const string& format, ...) {
		va_list args; // Variable argument list
		va_start(args, format); // Initialize the argument list
		writer << vformat(format, args); // Format and write to the buffered writer
		va_end(args); // Clean up the argument list
	}

	// Println writes a string followed by a newline to the console
	void Println(const string& s) {
		writer << s << endl; // Write the string to the buffered writer
	}

	// Close flushes the buffered writer
	void Close() {
		Flush(); // Ensure all buffered data is written out
	}

	// Flush flushes the buffered writer
	void Flush() {
		writer.flush(); // Flush the writer to output
	}
};

// NewConsole initializes a new Console instance
Console NewConsole() {
	return Console(cout); // Create a new writer for standard output
}

// PrintList prints a list of integers to the console
void PrintList(const vector<int>& list) {
	Console con = NewConsole(); // Create a new console instance
	defer con.Flush(); // Ensure flushing on function exit

	// Loop through the list and print each integer
	for (int i = 0; i < list.size(); i++) {
		if (i == 0) {
			con.Printf("%d", list[i]); // Print the first element without a leading space
		} else {
			con.Printf(" %d", list[i]); // Print subsequent elements with a leading space
		}
	}
	con.Println(""); // Print a newline after the list
}

// main function where the program execution begins
int main() {
	Console con = NewConsole(); // Create a new console instance
	defer con.Flush(); // Ensure flushing on function exit

	map<int, int> m; // Create a map to track unique integers
	vector<string> lines = ReadLongLines(4); // Read 4 lines from input
	vector<string> a = split(lines[1], " "); // Split the second line into individual strings

	// Convert strings to integers and store them in the map
	for (int i = 0; i < a.size(); i++) {
		int n = stoi(a[i]); // Convert string to integer
		m[n] = 1; // Add the integer to the map
	}

	vector<int> result; // Slice to hold the result integers
	vector<string> b = split(lines[3], " "); // Split the fourth line into individual strings

	// Process the integers from the fourth line
	for (int i = 0; i < b.size(); i++) {
		int n = stoi(b[i]); // Convert string to integer
		if (m.find(n) != m.end()) { // Check if the integer exists in the map
			m.erase(n); // Remove it from the map if it exists
		} else {
			m[n] = 1; // Add it to the map if it does not exist
		}
	}

	// Collect remaining integers from the map into the result slice
	for (auto it = m.begin(); it != m.end(); it++) {
		result.push_back(it->first); // Append the key to the result slice
	}

	// Sort the result slice in ascending order
	sort(result.begin(), result.end());

	// Print the sorted result
	for (int j = 0; j < result.size(); j++) {
		con.Printf("%d\n", result[j]); // Print each integer in the result
	}

	return 0;
}

