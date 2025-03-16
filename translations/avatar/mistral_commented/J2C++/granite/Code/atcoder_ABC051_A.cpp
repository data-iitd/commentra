

#include <iostream> // Include standard input/output stream objects
#include <string> // Include string class for string manipulation

using namespace std; // Use the standard namespace

int main() { // Main function to start the program
    string a; // Declare a string variable to store the input string

    // Read the input string from the console and store it in the 'a' variable
    getline(cin, a);

    // Replace all occurrences of ',' in the 'a' string with a single space and store the result in the 'a' variable
    replace(a.begin(), a.end(), ',','');

    // Print the modified string stored in the 'a' variable to the console
    cout << a << endl;

    return 0; // Return 0 to indicate successful program execution
}

