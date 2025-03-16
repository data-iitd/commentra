
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// ReadLongLines function reads long lines from standard input
vector<string> ReadLongLines(int times) {
	// Initialize result vector with the given size
	vector<string> result(times);
	// Initialize a new buffered reader
	string line;
	// Initialize readBytes variable to keep track of the total number of bytes read
	int readBytes = 2;

	// For each iteration, read a line from the standard input
	for (int i = 0; i < times; i++) {
		// Read a line from the standard input
		for (; readBytes > 0; readBytes--) {
			// Read a line from the standard input
			getline(cin, line);
			// Write the read line to the result vector
			result[i] += line;
		}
		// Seek back the standard input stream to the position before the last read operation
		cin.seekg(-readBytes, ios::cur);
	}
	// Return the result
	return result;
}

// Console type is used to manage the standard output
class Console {
public:
	// Initialize a new Console instance with the standard output as the writer
	Console() : writer(cout.rdbuf()) {}
	// Printf function prints formatted strings to the Console writer
	void Printf(const string& format, ...) {
		// Format and print the given arguments to the Console writer
		va_list args;
		va_start(args, format);
		writer.Pubseekoff(0, ios::cur, ios::out);
		vfprintf(writer, format.c_str(), args);
		va_end(args);
	}
	// Println function prints a newline character followed by the given string to the Console writer
	void Println(const string& s) {
		// Format and print the given string followed by a newline character to the Console writer
		writer.Pubseekoff(0, ios::cur, ios::out);
		fprintf(writer, "%s\n", s.c_str());
	}
	// Close function flushes the Console writer and closes it
	void Close() {
		// Flush and close the Console writer
		Flush();
	}
	// Flush function flushes the Console writer
	void Flush() {
		// Flush the Console writer
		writer.Pubsync();
	}
private:
	// Initialize a new Console instance with the standard output as the writer
	ostream& writer;
};

// PrintList function prints an integer slice to the standard output
void PrintList(const vector<int>& list) {
	// Initialize a new Console instance
	Console con;
	// Defer the Flush function to be called when the function returns
	defer(con.Flush());
	// Iterate through the given integer slice and print each element to the standard output
	for (int i = 0; i < list.size(); i++) {
		// If it's the first element, print it without a separator
		if (i == 0) {
			con.Printf("%d", list[i]);
		} else {
			// Otherwise, print it with a separator
			con.Printf(" %d", list[i]);
		}
	}
	// Print a newline character to the standard output
	con.Println("");
}

// main function is the entry point of the program
int main() {
	// Initialize a new Console instance
	Console con;
	// Defer the Flush function to be called when the function returns
	defer(con.Flush());

	// Initialize an empty map to store unique integers
	map<int, int> m;
	// Read long lines from the standard input
	vector<string> lines = ReadLongLines(4);
	// Split the second line into an integer slice
	vector<string> a = split(lines[1], " ");
	// Iterate through the integer slice and add each integer to the map
	for (int i = 0; i < a.size(); i++) {
		// Parse the integer from the string and add it to the map
		int n = stoi(a[i]);
		m[n] = 1;
	}

	// Read integers from the fourth line and add them to the map if they are not already present
	vector<string> b = split(lines[3], " ");
	for (int i = 0; i < b.size(); i++) {
		// Parse the integer from the string and add it to the map if it's not already present
		int n = stoi(b[i]);
		if (m.find(n) == m.end()) {
			m[n] = 1;
		}
	}

	// Extract the unique integers from the map and store them in a slice
	vector<int> result;
	for (auto it = m.begin(); it != m.end(); it++) {
		// Append the integer to the result slice
		result.push_back(it->first);
	}

	// Sort the result slice in ascending order
	sort(result.begin(), result.end());

	// Iterate through the sorted result slice and print each integer to the standard output
	for (int j = 0; j < result.size(); j++) {
		// Print each integer to the standard output
		con.Printf("%d\n", result[j]);
	}
}

