#include <iostream> // Including iostream for input and output
#include <string>   // Including string for string manipulation
#include <algorithm> // Including algorithm for reverse function

using namespace std;

int main() {
    long N; // Declaring variable N
    cin >> N; // Getting the value of N from user input

    long i = 357; // Initializing the variable i with a value of 357
    int c = 0; // Initializing the variable c with a value of 0

    while (i <= N) { // Starting a while loop that continues as long as i is less than or equal to N
        string s = to_string(i); // Converting the integer value of i to a string

        if (s.find('3') != string::npos && s.find('5') != string::npos && s.find('7') != string::npos) { // Checking if the string contains the digits 3, 5, and 7
            c++; // Incrementing the value of c by 1 if the condition is true
        }

        string sb; // Creating a new string for building the new number
        bool f = false; // Initializing a boolean variable f with a value of false

        for (int j = 0; j < s.length(); j++) { // Starting a for loop that iterates through each character in the string s
            char a = s[s.length() - 1 - j]; // Getting the character at the current index in reverse order

            if (f) { // If the boolean variable f is true, meaning we have found the first occurrence of 3, 5, or 7
                sb += a; // Appending the current character to the string
            } else { // If the boolean variable f is false, meaning we have not found the first occurrence of 3, 5, or 7 yet
                if (a == '3') { // Checking if the current character is a 3
                    sb += '5'; // If it is, append a 5 to the string and set f to true
                    f = true;
                } else if (a == '5') { // Checking if the current character is a 5
                    sb += '7'; // If it is, append a 7 to the string and set f to true
                    f = true;
                } else { // If the current character is not a 3, 5, or 7, append a 3 to the string and set f to true
                    sb += '3';
                    f = true;
                }
            }
        }

        if (!f) sb += '3'; // If we have not found any 3, 5, or 7 in the string, append a 3 to the string

        reverse(sb.begin(), sb.end()); // Reversing the string
        i = stoll(sb); // Converting the reversed string back to a long integer and assigning it to the variable i
    }

    cout << c << endl; // Printing the value of c to the console
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
