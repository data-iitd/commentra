// Importing necessary C++ libraries for this program
#include <iostream> // For input and output
#include <string>   // For string manipulation

int main() {
    // Creating a variable to read user input
    int x;
    
    // Reading an integer value from the user input
    std::cin >> x;

    // Determining a boolean value based on the condition x equals to 1
    bool boolValue = (x == 1);

    // Calculating the result based on the boolean value
    int result = !boolValue ? 1 : 0;

    // Writing the result to the standard output
    std::cout << result << std::endl;

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
