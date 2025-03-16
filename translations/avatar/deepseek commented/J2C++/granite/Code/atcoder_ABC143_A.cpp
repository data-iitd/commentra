
#include <iostream> // Including the necessary libraries for input/output operations
#include <string> // Including the necessary library for string manipulation

using namespace std; // Using the standard namespace for input/output operations

int main() { // Defining the main function where execution begins
    try { // Beginning of try block to handle potential exceptions
        string s; // Declaring a string variable to store input
        getline(cin, s); // Reading input from the standard input and storing it in the string variable
        stringstream ss(s); // Creating a stringstream object to manipulate the string variable
        int a, b, c; // Declaring integer variables to store the input values
        ss >> a >> b; // Extracting the first two integers from the string variable and storing them in the integer variables
        c = a - b * 2; // Performing a mathematical operation to calculate a result
        if (c < 0) c = 0; // Checking if the result is negative and setting it to 0 if true
        cout << c << endl; // Printing the result to the standard output
    } catch (exception& e) { // Catch block to handle exceptions
        // Handle exceptions (not implemented in this code)
    }
    return 0; // Returning 0 to indicate successful execution
}

