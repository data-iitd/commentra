#include <iostream>
#include <string>

int main() {
	// Declare a string variable to hold user input
	std::string a;
	
	// Read input from the user and store it in `a`
	std::cin >> a;
	
	// Replace all occurrences of "1" with "0" in the string `a`
	std::string tmp = std::string(a.size(), '0');
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '1') {
			tmp[i] = '0';
		}
	}
	
	// Store the result of the first replacement in a temporary variable `tmp`
	// Replace all occurrences of "9" with "1" in the string `tmp`
	std::string b = std::string(tmp.size(), '1');
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '9') {
			b[i] = '1';
		}
	}
	
	// Store the result of the second replacement in the variable `b`
	// Replace all occurrences of "0" with "9" in the string `b`
	std::string ans = std::string(b.size(), '9');
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '0') {
			ans[i] = '9';
		}
	}
	
	// Print the final result to the console
	std::cout << ans << std::endl;
}

