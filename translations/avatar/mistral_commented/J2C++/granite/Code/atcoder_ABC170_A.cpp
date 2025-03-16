
// Importing necessary C++ libraries for reading input from the console and writing output to the console
#include <iostream>
#include <string>
#include <vector>

// Main function is the entry point of the C++ application
int main() {

    // Creating vector of strings to store input array
    std::vector<std::string> input_array;

    // Reading input array from the console
    std::string input_string;
    while (std::cin >> input_string) {
        input_array.push_back(input_string);
    }

    // Initializing result variable to 0
    int result = 0;

    // Iterating through each string in the input array
    for (const auto& str : input_array) {

        // Incrementing result variable for each non-zero string encountered
        if (str!= "0") {
            result++;
        }

        // Breaking the loop if a zero string is encountered
        else {
            break;
        }
    }

    // Writing the result to the console
    std::cout << result << std::endl;

    // End of code
    return 0;
}
