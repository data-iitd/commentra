#include <iostream>
#include <string>

using namespace std;

int main()
{
    string mes; // Declare a string variable'mes' to store the input string

    cin >> mes; // Read a string from the standard input and store it in'mes' variable

    // Logic starts here

    cout << mes[0] << mes.size() - 2 << mes[mes.size() - 1] << endl; // Print the first character, length - 2 and last character of the input string

    return 0; // Indicate successful termination of the program
}

