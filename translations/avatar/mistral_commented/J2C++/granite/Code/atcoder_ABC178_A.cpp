
// Importing necessary C++ libraries for this program
#include <iostream> // For user input and output
#include <string>   // For string manipulation

int main() {
    // Creating a new string variable to store the user input
    std::string input;

    // Reading a string value from the user input
    std::cin >> input;

    // Determining a boolean value based on the condition input equals to "1"
    bool bool = input == "1"? true : false;

    // Calculating the result based on the boolean value
    int result =!bool? 1 : 0;

    // Writing the result to the standard output
    std::cout << result << std::endl;

    // Returning 0 to indicate successful execution of the program
    return 0;
}

