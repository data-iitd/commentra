#include <iostream> // Including header file for input/output operations
#include <string> // Including header file for string operations
#include <sstream> // Including header file for stringstream operations

using namespace std; // Using standard namespace

int main() { // Defining main function
    try { // Beginning of try block to handle potential exceptions
        string input; // Declaring a string variable to store input
        getline(cin, input); // Reading input from standard input
        stringstream ss(input); // Creating a stringstream object to read input
        string x[2]; // Declaring an array of strings to store input
        ss >> x[0] >> x[1]; // Reading input from stringstream and storing it in the array
        int a = stoi(x[0]); // Converting the first element of the array to an integer
        int b = stoi(x[1]); // Converting the second element of the array to an integer
        int c = a - b * 2; // Performing a mathematical operation to calculate a result
        if (c < 0) c = 0; // Checking if the result is negative and setting it to 0 if true
        cout << c << endl; // Printing the result to the standard output
    } catch (exception e) { // Catch block to handle exceptions
        // Handle exceptions (not implemented in this code)
    }
    return 0; // Returning 0 to indicate successful execution
}

