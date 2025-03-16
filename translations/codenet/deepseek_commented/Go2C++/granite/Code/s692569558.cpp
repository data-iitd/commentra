

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
	// Create a string to hold the input
	std::string input;
	
	// Read the first line of input (which we will ignore)
	std::getline(std::cin, input);
	
	// Read the second line of input
	std::getline(std::cin, input);
	
	// Create a stringstream to split the input string
	std::stringstream ss(input);
	
	// Create a vector of integers to hold the converted values
	std::vector<int> numbers;
	
	// Convert each string in the input to an integer and add it to the vector
	int num;
	while (ss >> num) {
		numbers.push_back(num);
	}
	
	// Initialize the sum variable to hold the result
	int sum = 0;
	
	// Calculate the sum of the products of all pairs of integers in the vector
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			sum += numbers[i] * numbers[j];
		}
	}
	
	// Print the result
	std::cout << sum << std::endl;
	
	// End the program
	return 0;
}

