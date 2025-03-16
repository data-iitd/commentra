
#include <iostream>  // Include standard input/output library
#include <string>  // Include standard library for strings

int main(){  // Beginning of the main function
	std::string S;  // Declare a string variable 'S'

	std::cin >> S;  // Read a string of six characters from the standard input and store it in the string 'S'

	for(int i = 0; i < S.length() - 1; i++){  // Iterate through each character in the string 'S'
		if(S[i] == 'A' && S[i + 1] == 'C'){  // Check if the current character is 'A' and the next character is 'C'
			std::cout << "Yes\n";  // If so, print 'Yes' to the standard output
			return 0;  // And exit the program
		}
	}

	std::cout << "No\n";  // If no pair of 'AC' is found, print 'No' to the standard output
	return 0;  // End of the main function
}
