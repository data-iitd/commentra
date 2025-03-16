
#include <iostream>
#include <string>

int main() {
	// Declare a variable to hold the input string
	std::string a;
	
	// Read input from the user and store it in variable 'a'
	std::cin >> a;
	
	// Replace all occurrences of '1' with '0' in the input string
	std::string tmp = std::regex_replace(a, std::regex("1"), "0");
	
	// Replace all occurrences of '9' with '1' in the modified string
	std::string b = std::regex_replace(tmp, std::regex("9"), "1");
	
	// Replace all occurrences of '0' with '9' in the second modified string
	std::string ans = std::regex_replace(b, std::regex("0"), "9");
	
	// Print the final transformed string
	std::cout << ans << std::endl;
	
	return 0;
}
