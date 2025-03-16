#include <iostream> // Including iostream for input/output operations
#include <string> // Including string for string operations
#include <cstdlib> // Including cstdlib for string operations
#include <cstring> // Including cstring for string operations
using namespace std; // Using standard namespace

int main() { // Defining the main function
    string a; // Declaring a string variable
    getline(cin, a); // Reading a line of input from the user
    a.erase(remove(a.begin(), a.end(), ','), a.end()); // Removing commas from the input string
    cout << a << endl; // Printing the manipulated string
    return 0; // Returning 0 to indicate successful execution
}
