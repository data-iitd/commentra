#include <iostream>  // Include iostream for input/output operations
#include <string>  // Include string for string operations

int main(){  // Beginning of the main function
	int i;  // Declare an integer variable 'i'
	std::string S;  // Declare a string 'S'

	std::cin >> S;  // Read a string from the standard input and store it in the string 'S'

	for(i = 0; i < S.length(); i++){  // Iterate through each character in the string 'S'
		if(S[i] == 'A' && S[i + 1] == 'C'){  // Check if the current character is 'A' and the next character is 'C'
			std::cout << "Yes" << std::endl;  // If so, print 'Yes' to the standard output
			return 0;  // And exit the program
		}
	}

	std::cout << "No" << std::endl;  // If no pair of 'AC' is found, print 'No' to the standard output
	return 0;  // End of the main function
}
