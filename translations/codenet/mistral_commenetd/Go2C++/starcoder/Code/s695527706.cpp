// Package main is the entry point of the program
#include <iostream>
#include <string>

int main() {
	// Declare two variables, n and s
	int n;
	std::string s;

	// Read the input from the standard input
	std::cin >> n >> s;

	// Print the result of the strings.Count function
	std::cout << std::count(s.begin(), s.end(), 'A') << std::endl;
}

// The main function is the entry point of the program
int main() {
	// Declare two variables, n and s
	int n;
	std::string s;

	// Read the input from the standard input
	std::cin >> n >> s;

	// Call the strings.Count function to count the number of occurrences of "ABC" in the string s
	// Print the result using the fmt.Println function
	std::cout << std::count(s.begin(), s.end(), 'A') << std::endl;
}

// This is the end of the code

