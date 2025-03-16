#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic array
#include <cmath>    // Including the cmath library for mathematical functions

using namespace std;

int main() {
    long x;
    cin >> x; // Reading the first number from the standard input stream

    vector<long> list; // Creating a vector to store digits

    // The following while loop runs as long as the number x is greater than zero
    while (x > 0) {
        long r = x % 10; // Storing the last digit of the number x in the variable r

        // The following if statement checks if the difference between 9 and the last digit r is less than r itself
        if (9 - r < r) {
            // The following nested if statement checks if both x and the difference between 9 and the last digit r are zero
            if (x / 10 == 0 && 9 - r == 0) {
                list.push_back(r); // Adding the last digit r to the vector if it is the only digit in the number x
            } else {
                list.push_back(9 - r); // Adding the number 9 minus the last digit r to the vector
            }
        } else {
            list.push_back(r); // Adding the last digit r to the vector
        }

        x = x / 10; // Dividing the number x by 10 to get the next digit
    }

    long newNumber = 0; // Initializing the variable newNumber to 0 to store the final number
    int pow = 0; // Initializing the variable pow to 0 to be used as the power of 10

    // The following for loop runs through each digit in the vector and calculates the new number
    for (int i = 0; i < list.size(); i++) {
        newNumber += list[i] * static_cast<long>(pow(10, pow)); // Adding the digit multiplied by the power of 10
        pow++;
    }

    cout << newNumber << endl; // Printing the final number to the standard output stream

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
