
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Main {
    long A, B, K; // Declaring variables A, B, and K of type long
    long x, y; // Declaring variables x and y of type long

public:
    Main(string input) { // Constructor for the Main class that takes a string as a parameter
        stringstream ss(input); // Creating a stringstream to read from the input string
        string token; // Declaring a string named token

        ss >> A >> B >> K; // Reading the first line of input and splitting it into tokens using the space character as a delimiter
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
        cout << x << " " << y << endl; // Printing the values of x and y separated by a space character
    }
};

int main() {
    string input; // Declaring a string named input
    getline(cin, input); // Reading the first line of input
    Main ins(input); // Creating an instance of the Main class and passing the input string as a parameter
    ins.calc(); // Calling the calc() method to perform the calculations
    ins.showResult(); // Calling the showResult() method to display the results
    return 0;
}

