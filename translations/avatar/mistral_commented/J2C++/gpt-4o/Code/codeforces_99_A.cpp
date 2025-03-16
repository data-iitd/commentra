#include <iostream> // Including iostream for input and output
#include <string>   // Including string for string manipulation
#include <sstream>  // Including sstream for string stream
#include <cmath>    // Including cmath for mathematical functions
#include <iomanip>  // Including iomanip for input/output manipulation

using namespace std;

int main() {
    string str; // Declaring a string to read the entire line from the console
    getline(cin, str); // Reading a line of input from the console and storing it in the string str

    size_t dotIndex = str.find_last_of('.'); // Finding the index of the last occurrence of '.' character in the string

    // Checking if the character before the '.' character is '9'
    if (dotIndex > 0 && str[dotIndex - 1] == '9') {
        cout << "GOTO Vasilisa." << endl; // Printing the message if the condition is true
    }
    // Checking if the character after the '.' character is a digit greater than 4
    else if (dotIndex < str.length() - 1 && isdigit(str[dotIndex + 1]) && (str[dotIndex + 1] - '0') > 4) {
        string _str = str.substr(0, dotIndex); // Creating a substring of str from the beginning to the index of '.' character
        // Performing big integer addition and printing the result
        cout << stoll(_str) + 1 << endl; // Using stoll to convert string to long long and adding 1
    }
    // Printing the substring of the string str from the beginning to the index of '.' character
    else {
        cout << str.substr(0, dotIndex) << endl; // Printing the substring
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
