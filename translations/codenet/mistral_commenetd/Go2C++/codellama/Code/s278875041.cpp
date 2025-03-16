// Importing required headers
#include <iostream>
#include <string>

// Declaring a function 'main'
int main()
{
	// Declaring a variable 'a' of type string
	std::string a;

	// Reading a string input from the user using std::cin
	std::cin >> a;

	// Declaring a temporary variable 'tmp' of type string
	std::string tmp = a;

	// Replacing all occurrences of '1' with '0' in the string 'a'
	// and storing the result in the variable 'tmp'
	tmp.replace(tmp.begin(), tmp.end(), "1", "0");

	// Declaring a variable 'b' of type string
	std::string b = tmp;

	// Replacing all occurrences of '9' with '1' in the string 'tmp'
	// and storing the result in the variable 'b'
	b.replace(b.begin(), b.end(), "9", "1");

	// Declaring a variable 'ans' of type string
	std::string ans = b;

	// Replacing all occurrences of '0' with '9' in the string 'b'
	// and storing the result in the variable 'ans'
	ans.replace(ans.begin(), ans.end(), "0", "9");

	// Printing the final answer using std::cout
	std::cout << ans << std::endl;

	// Ending the program
	return 0;
}

// Ending the code with comment "