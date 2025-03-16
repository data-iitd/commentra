
#include <iostream>
#include <string> // Including the string header file for string manipulation functions

int main() {
	int n; // Declaring an integer variable to store the number of inputs
	std::string s; // Declaring a string variable to store the input string
	std::cin >> n >> s; // Reading input from the user and storing it in n and s
	std::cout << std::count(s.begin(), s.end(), "ABC") << std::endl; // Counting the occurrences of "ABC" in s and printing the result
	return 0;
}
