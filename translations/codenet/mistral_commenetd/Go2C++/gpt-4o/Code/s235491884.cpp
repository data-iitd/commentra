// Include the necessary header files
#include <iostream>
#include <string>

using namespace std;

// The main function is the entry point of the program
int main() {
    // Declare a variable 's' of type string
    string s;
    // Use 'cin' to read a string input from the standard input
    cin >> s;

    // Count the number of occurrences of the character 'o' in the string 's'
    int n = count(s.begin(), s.end(), 'o');

    // Calculate the result by adding 700 to the product of 100 and the number of occurrences of 'o' in the string
    int result = 700 + n * 100;
    // Use 'cout' to print the result to the standard output
    cout << result << endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
