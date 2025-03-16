

#include <iostream> // Importing the 'iostream' library for input/output operations

int main() {
    // Declaring a variable 'data' of type 'int' to read user input
    int data;

    // Reading user input and storing it in the 'data' variable
    std::cin >> data;

    // Declaring a variable'result' of type 'int' to store the result
    int result;

    // Assigning the value of 'data' cubed to the'result' variable
    result = data * data * data;

    // Printing the result using the 'cout' object from 'iostream' library
    std::cout << result << std::endl; // Printing the result with newline character '\n'

    return 0; // Returning 0 to indicate successful execution of the program
}

