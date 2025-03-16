#include <iostream> // Include the iostream library for input and output

int main() {
    int data; // Declare a variable to hold the input integer
    std::cin >> data; // Read an integer value from standard input and store it in 'data'
    
    int result = data * data * data; // Calculate the cube of the input value
    std::cout << result << std::endl; // Print the result to standard output

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
