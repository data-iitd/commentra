
#include <iostream> // Importing the iostream library for input/output operations
#include <string> // Importing the string library for string manipulation functions

int main() {
	std::string s; // Declaring a string variable to store user input
	std::cin >> s; // Reading input from the user and storing it in the variable s

	int n = std::count(s.begin(), s.end(), 'o'); // Counting the number of occurrences of "o" in the string s and storing the result in n
	std::cout << 700 + n*100 << std::endl; // Printing the final score based on the count of "o" characters

	return 0; // Returning 0 to indicate successful execution of the program
}

