
#include <iostream> // Including the standard input/output stream objects
#include <string> // Including the string class
#include <sstream> // Including the string stream class

using namespace std; // Using the standard namespace

int main() { // Defining the main function
    string a; // Declaring a string variable a
    getline(cin, a); // Reading a line of input from the user and storing it in the string variable a
    stringstream ss; // Declaring a string stream object ss
    ss << a; // Inserting the contents of the string variable a into the string stream object ss
    string b; // Declaring a string variable b
    getline(ss, b, ','); // Reading from the string stream object ss until a comma is encountered and storing the result in the string variable b
    cout << b << endl; // Printing the manipulated string
    return 0; // Returning 0 to indicate successful execution of the program
}

