// 2018-07-29T20:36:21+0800
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cout << "Enter a string: ";
	cin >> s;

	// Replace all occurrences of the string "2017" in the string `s` with the string "2018".
	s = s.replace("2017", "2018", -1);

	// Print the modified string to the standard output.
	cout << "Modified string: " << s << endl;
}

// End of code.

Translate the above C++ code to Python and end with comment "