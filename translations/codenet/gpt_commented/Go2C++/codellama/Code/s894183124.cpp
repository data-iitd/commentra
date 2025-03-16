#include <iostream>
#include <string>

using namespace std;

int main() {
	// Declare variables to hold the integer input and the string input
	int n;
	string s;
	
	// Read an integer from standard input
	cin >> n;
	
	// Read a string from standard input
	cin >> s;
	
	// Count the occurrences of the substring "ABC" in the input string
	// and print the result
	cout << count(s.begin(), s.end(), 'A') << endl;
	
	return 0;
}

