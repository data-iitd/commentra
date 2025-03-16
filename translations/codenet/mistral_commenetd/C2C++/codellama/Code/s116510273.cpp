#include <iostream>
#include <string>

// Include necessary libraries for standard input/output and string manipulation

using namespace std;

int main()
{
    string mes; // Declare a string 'mes' to store the input string

    cin >> mes; // Read a string from the standard input and store it in 'mes' string

    // Logic starts here

    cout << mes[0] << mes.length()-2 << mes[mes.length()-1] << endl; // Print the first character, length - 2 and last character of the input string

    return 0; // Indicate successful termination of the program
}

