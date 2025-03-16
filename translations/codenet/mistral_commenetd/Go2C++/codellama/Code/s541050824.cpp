// Importing required packages
#include <iostream>
#include <string>
#include <vector>

// Initializing variables
std::string input;
std::vector<std::string> input_vector;

// Main function
int main() {
	// Reading input
	std::getline(std::cin, input);
	input_vector = split(input, " ");

	// Printing output
	for (int i = 0; i < input_vector.size(); i++) {
		std::cout << input_vector[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

// Function to split a string
std::vector<std::string> split(std::string input, std::string delimiter) {
	std::vector<std::string> result;
	size_t pos = 0;
	std::string token;
	while ((pos = input.find(delimiter)) != std::string::npos) {
		token = input.substr(0, pos);
		result.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	result.push_back(input);
	return result;
}

