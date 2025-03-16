#include <iostream> // Including the input/output stream library
#include <iomanip>  // Including the library for input/output manipulators

int main() { // Starting the main function
    int a, b, c, d, e, f; // Declaring variables a to f as integers
    double x, y; // Declaring variables x and y as double precision floating point numbers

    while (true) { // Starting an infinite loop
        if (std::cin >> a >> b >> c >> d >> e >> f) { // Checking if the input is valid and can be read into the variables
            // Input is valid, so process it
            y = static_cast<double>(c * d - f * a) / (b * d - e * a); // Calculating the value of y using the given formula
            x = static_cast<double>(c * e - f * b) / (a * e - d * b); // Calculating the value of x using the given formula
            if (y <= 0.0005) { // Checking if y is less than or equal to a very small positive number
                y = 0; // If so, set y to 0
            }
            if (x <= 0.0005) { // Checking if x is less than or equal to a very small positive number
                x = 0; // If so, set x to 0
            }
            std::cout << std::fixed << std::setprecision(3) << x << " " << y << std::endl; // Printing the values of x and y to the standard output with three decimal places
        } else { // Input is invalid or end of file reached
            break; // Exiting the loop
        }
    }

    return 0; // Ending the main function with a return value of 0
}

// <END-OF-CODE>
