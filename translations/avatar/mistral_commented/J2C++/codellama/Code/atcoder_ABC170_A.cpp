// Including necessary C++ headers for reading input from the console and writing output to the console
#include <iostream>
#include <string>

// Main function is the entry point of the C++ application
int main() {

    // Creating a string array to store the input array
    std::string input_array[1000];

    // Creating a variable to store the result
    int result = 0;

    // Reading input array from the console
    for (int i = 0; i < 1000; i++) {
        std::cin >> input_array[i];
    }

    // Iterating through each string in the input array
    for (int i = 0; i < 1000; i++) {

        // Incrementing result variable for each non-zero string encountered
        if (input_array[i] != "0") {
            result++;
        }

        // Breaking the loop if a zero string is encountered
        if (input_array[i] == "0") {
            break;
        }
    }

    // Writing the result to the console
    std::cout << result << std::endl;

    // Ending the program
    return 0;
}

