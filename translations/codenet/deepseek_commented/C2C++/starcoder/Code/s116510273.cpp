#include <iostream>
#include <string> // Include the string library for string manipulation functions

using namespace std;

int main()
{
    string mes; // Declare a string to store the input string
    cin >> mes; // Read a string input from the user and store it in'mes'

    // Calculate the length of the string excluding the first and last character
    size_t length = mes.length() - 2;

    // Print the first character, the calculated length, and the last character of the string
    cout << mes[0] << length << mes[mes.length() - 1] << endl;

    return 0; // Return 0 to indicate successful execution
}

