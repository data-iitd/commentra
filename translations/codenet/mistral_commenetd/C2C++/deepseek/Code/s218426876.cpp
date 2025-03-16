#include <iostream> // Include iostream library for input/output operations
#include <string> // Include string library for string manipulation functions

int main() // Function definition for main function
{
	int i; // Initialize integer variable 'i'
	int sum = 0; // Initialize integer variable 'sum' to zero
	int flag = 0; // Initialize integer variable 'flag' to zero
	std::string x; // Initialize string variable 'x'

	// Read a string from standard input and store it in 'x' variable
	std::cout << "Enter a string of digits separated by spaces or newline: ";
	std::cin >> x;

	do{ // Begin a do-while loop

		// Initialize sum to zero before processing each string
		sum = 0;

		// Process each character in the string 'x'
		for(i = 0; i < x.length(); i++){
			// Add the integer value of the character to the sum
			sum += x[i] - '0';
		}

		// Print the sum of digits in the current string
		std::cout << "Sum of digits in current string: " << sum << std::endl;

		// Read next string from standard input
		std::cout << "Enter a string of digits separated by spaces or newline: ";
		std::cin >> x;

	}while(x[0] != '0'); // Continue the loop until the first character of the input string is '0'

	return 0; // Function returns 0 upon successful execution
}
