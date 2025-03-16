#include <iostream> // Including necessary header for input and output
#include <sstream>  // Including header for string stream
#include <string>   // Including header for string
#include <stdexcept> // Including header for exceptions

class Main {
    long A, B, K; // Declaring variables A, B, and K of type long
    long x, y; // Declaring variables x and y of type long

public:
    Main(std::istream& in) { // Constructor for the Main class that takes an input stream as a parameter
        std::string line; // Declaring a string to hold the input line
        std::getline(in, line); // Reading a line of input

        std::istringstream iss(line); // Creating a string stream from the input line
        if (!(iss >> A >> B >> K)) { // Parsing the input values
            throw std::runtime_error("Invalid input"); // Throwing an exception if input is invalid
        }
    }

    void calc() { // Method to perform the calculations
        x = A; // Assigning the value of A to x
        y = B; // Assigning the value of B to y

        x = A - K; // Subtracting K from A and assigning the result to x

        if (x < 0) { // Checking if x is negative
            y = B + x; // If x is negative, adding the absolute value of x to B and assigning the result to y
            x = 0; // Setting x to zero
        }

        if (y < 0) { // Checking if y is negative
            y = 0; // If y is negative, setting it to zero
        }
    }

    void showResult() { // Method to display the results
        std::cout << x << " " << y << std::endl; // Printing the values of x and y separated by a space character
    }
};

int main() {
    Main ins(std::cin); // Creating an instance of the Main class and passing the standard input stream as a parameter
    ins.calc(); // Calling the calc() method to perform the calculations
    ins.showResult(); // Calling the showResult() method to display the results
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
