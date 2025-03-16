
#include <iostream> // Importing the iostream library for input/output operations

int main() {
    int data; // Declare an integer variable to hold the input value
    std::cin >> data; // Read an integer value from standard input and store it in 'data'
    
    int result = data * data * data; // Calculate the cube of the input value
    std::cout << result << std::endl; // Print the result to standard output
    
    return 0; // Return 0 to indicate successful execution
}

