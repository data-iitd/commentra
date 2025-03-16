// Including the header file for input/output operations
#include <iostream>

// Defining the main function
int main() {
	// Declaring and initializing the variable 'n' for the number of characters in the string 's'
	int n;
	// Declaring and initializing the variable 's' for the string
	std::string s;

	// Reading input from the user
	std::cin >> n >> s;

	// Declaring and initializing the variable 'max' for the maximum count
	int max = 0;
	// Declaring and initializing the variable 'cnt' for the current count
	int cnt = 0;

	// Iterating through each character in the string 's'
	for (int i = 0; i < n; i++) {
		// Checking if the character is 'I'
		if (s[i] == 'I') {
			// Incrementing the current count
			cnt++;
		} else {
			// Decrementing the current count
			cnt--;
		}

		// Updating the maximum count if the current count is greater
		if (cnt > max) {
			max = cnt;
		}
	}

	// Printing the maximum count
	std::cout << max << std::endl;

	// End of the code
	return 0;
}

