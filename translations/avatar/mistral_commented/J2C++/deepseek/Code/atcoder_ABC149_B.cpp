#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Main {
public:
    long long A, B, K; // Declaring variables A, B, and K of type long long
    long long x, y; // Declaring variables x and y of type long long

    Main(istream& in) { // Constructor for the Main class that takes an istream as a parameter
        string line; // Declaring a string named line
        getline(in, line); // Reading a line from the input stream
        stringstream ss(line); // Creating a stringstream object from the line
        ss >> A >> B >> K; // Extracting the values from the stringstream into variables A, B, and K
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
    Main ins(cin); // Creating an instance of the Main class and passing the cin input stream as a parameter
    ins.calc(); // Calling the calc() method to perform the calculations
    ins.showResult(); // Calling the showResult() method to display the results
    return 0;
}

