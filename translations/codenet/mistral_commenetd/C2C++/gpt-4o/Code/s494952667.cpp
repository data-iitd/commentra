#include <iostream> // Standard Input/Output Library
#include <string>   // String Library

using namespace std;

int main()
{
    string str; // Declare a string variable named 'str'
    cout << "Enter a string: "; // Prompt the user to enter a string
    cin >> str; // Read a string from the standard input and store it in the 'str' variable

    cout << "Reversed string: "; // Print a message to indicate that the reversed string will be printed

    for (int i = str.length() - 1; i >= 0; i--) { // Use a for loop to print each character of the string in reverse order
        cout << str[i]; // Print the character at the index 'i' of the 'str' variable
    }

    cout << endl; // Print a newline character
    return 0; // Indicate successful execution
}

// <END-OF-CODE>
