#include <iostream>
#include <string>

using namespace std; // This line saves us from having to write std:: before every standard library function and object we use

int main() { // The main function is the entry point of the program
    string s; // Declare a string variable named s to store the user input
    cin >> s; // Read a string input from the standard input stream (cin) and store it in the s variable

    int a, z; // Declare two integer variables named a and z

    for(int i = 0; i < s.size(); i++) { // This for loop iterates through each character in the string s
        if (s[i] == 'A') { // Check if the current character is 'A'
            a = i; // If it is, assign the index of the character to the variable a
            break; // Exit the loop once 'A' is found
        }
    }

    for(int i = s.size() - 1; i >= 0; i--) { // This for loop iterates through the string in reverse order
        if (s[i] == 'Z') { // Check if the current character is 'Z'
            z = i; // If it is, assign the index of the character to the variable z
            break; // Exit the loop once 'Z' is found
        }
    }

    cout << z - a + 1 << endl; // Output the difference between the indices of 'Z' and 'A' plus one

    return 0; // Indicate that the program has run successfully
}
