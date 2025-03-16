

#include <iostream> // Including the necessary header files for input/output operations
#include <string>
#include <sstream>

using namespace std; // Using the standard namespace for input/output operations

int main() {
    int N; // Declaring and initializing the variable N with a value read from the user
    cin >> N;

    long i = 357; // Initializing the variable i with a value of 357
    int c = 0; // Initializing the variable c with a value of 0

    while (i <= N) { // Starting a while loop that continues as long as i is less than or equal to N
        string s = to_string(i); // Converting the integer value of i to a string

        if (s.find("3")!= string::npos && s.find("5")!= string::npos && s.find("7")!= string::npos) { // Checking if the string contains the digits 3, 5, and 7
            c++; // Incrementing the value of c by 1 if the condition is true
        }

        stringstream ss; // Creating a new stringstream object
        bool f = false; // Initializing a boolean variable f with a value of false

        for (int j = 0; j < s.length(); j++) { // Starting a for loop that iterates through each character in the string s
            char a = s[s.length() - 1 - j]; // Getting the character at the current index in reverse order

            if (f) { // If the boolean variable f is true, meaning we have found the first occurrence of 3, 5, or 7
                ss << a; // Appending the current character to the stringstream object
            } else { // If the boolean variable f is false, meaning we have not found the first occurrence of 3, 5, or 7 yet
                if (a == '3') { // Checking if the current character is a 3
                    ss << '5'; // If it is, append a 5 to the stringstream object and set f to true
                    f = true;
                } else if (a == '5') { // Checking if the current character is a 5
                    ss << '7'; // If it is, append a 7 to the stringstream object and set f to true
                    f = true;
                } else { // If the current character is not a 3, 5, or 7, append a 3 to the stringstream object and set f to true
                    ss << '3';
                    f = true;
                }
            }
        }

        if (!f) ss << '3'; // If we have not found any 3, 5, or 7 in the string, append a 3 to the stringstream object

        string t = ss.str(); // Converting the stringstream object to a string and assigning it to the variable t
        reverse(t.begin(), t.end()); // Reversing the string t
        i = stol(t); // Converting the reversed string back to a long integer and assigning it to the variable i
    }

    cout << c << endl; // Printing the value of c to the console

    return 0; // Returning 0 to indicate successful execution of the program
}

