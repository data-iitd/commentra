// by syu
#include <iostream> // Importing iostream for input/output
#include <cstdio> // Importing cstdio for formatted I/O
#include <cstdlib> // Importing cstdlib for general I/O interfaces
#include <cstring> // Importing cstring for string conversion functions
#include <string> // Importing string for string functions
#include <sstream> // Importing sstream for stringstream

using namespace std; // Using standard namespace

// Initialize a new Scanner to read from standard input
Scanner in(cin, 0);

int main() {
	// Read two integers n and k from input
	int n, k;
	cin >> n >> k;
	
	// Check if n is divisible by k
	if (n % k == 0) {
		// If divisible, print 0
		cout << 0 << endl;
	} else {
		// If not divisible, print 1
		cout << 1 << endl;
	}
	
	return 0;
}

// Scanner struct wraps istream for custom functionality
class Scanner {
	public:
		// Constructor for Scanner
		Scanner(istream& in, int max) : in(in), max(max) {
			// Set the buffer size for the scanner
			in.rdbuf()->pubsetbuf(buf, max);
		}
		
		// Int reads the next token from the input and converts it to an integer
		int Int() {
			in >> token; // Read the next token
			return stoi(token); // Return the parsed integer
		}
		
	private:
		istream& in; // Input stream
		int max; // Maximum buffer size
		char buf[1048576]; // Buffer for the input stream
		string token; // Token for the current word
};

// isSpace checks if a character is a whitespace character
bool isSpace(char c) {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t'; // Return true for whitespace
}

// scanWords is a split function for istream that splits input into words
istream& scanWords(istream& in, string& token) {
	// Skip leading whitespace
	while (isSpace(in.peek())) {
		in.get();
	}
	
	// Find the end of the next word
	while (!isSpace(in.peek())) {
		token += in.get();
	}
	
	return in;
}

// Pln is a helper function to print a line with a newline
void Pln(string s) {
	cout << s << endl; // Print the provided string
}

