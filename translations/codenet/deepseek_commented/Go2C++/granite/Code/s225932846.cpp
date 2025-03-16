
#include <iostream>
#include <string>

int main() {
	// Read a string S from the standard input
	std::string S;
	std::cin >> S;

	// Iterate over the string in steps of 2, starting from index 2 up to the length of the string
	for (int i = 2; i <= S.length(); i = i + 2) {
		// Check if the substring from the start to the middle of the remaining part of the string
		// is equal to the substring from the middle of the remaining part of the string to the end
		if (S.substr(0, (S.length() - i) / 2) == S.substr((S.length() - i) / 2, S.length() - i)) {
			// If a match is found, print the length of the string minus the current step size and break out of the loop
			std::cout << (S.length() - i) << std::endl;
			break;
		}
	}
}

