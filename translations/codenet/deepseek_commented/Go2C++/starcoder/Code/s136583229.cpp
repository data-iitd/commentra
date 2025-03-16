#include <iostream>

int main() {
    // Declare a variable to store the input data
    int data;
    
    // Read an integer value from the standard input and store it in `data`
    std::cin >> data;
    
    // Calculate the cube of `data` and store the result in `result`
    int result = data * data * data;
    
    // Print the result
    std::cout << result << std::endl;
}

