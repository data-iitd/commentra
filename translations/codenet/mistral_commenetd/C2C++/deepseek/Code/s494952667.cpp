#include <iostream> // Standard Input/Output Stream Library
#include <string> // String Library

using namespace std; // Use the standard namespace

string str; // Declare and initialize a string named 'str'
int i, len; // Declare and initialize two integer variables named 'i' and 'len'

int main()
{
    cout << "Enter a string: "; // Prompt the user to enter a string
    cin >> str; // Read a string from the standard input and store it in the 'str' variable

    len = str.length(); // Calculate the length of the string stored in the 'str' variable and assign it to the 'len' variable

    cout << "Reversed string: "; // Print a message to indicate that the reversed string will be printed

    for(i = len-1; i >= 0; i--){ // Use a for loop to print each character of the string in reverse order
        cout << str[i]; // Print the character at the index 'i' of the 'str' variable
    }

    cout << endl; // Print a newline character
    return 0; // Indicate successful execution
}
