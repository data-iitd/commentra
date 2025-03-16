#include <iostream> // Including the iostream library for input/output
#include <string>   // Including the string library for string manipulation

using namespace std; // Using the standard namespace

int main() {
    long N; // Declaring a variable to hold the upper limit
    cin >> N; // Reading an integer N from the user
    long i = 357; // Initializing the starting number
    int c = 0; // Initializing the counter for valid numbers

    // Main loop to find numbers containing '3', '5', and '7'
    while (i <= N) {
        string s = to_string(i); // Converting the current number to a string
        if (s.find('3') != string::npos && s.find('5') != string::npos && s.find('7') != string::npos) {
            c++; // Incrementing the counter if all required digits are present
        }

        // Building a new number by replacing the last digit
        string newNumber;
        bool f = false;
        for (int j = s.length() - 1; j >= 0; j--) {
            char a = s[j];
            if (f) {
                newNumber += a; // Appending characters after the replacement
            } else {
                if (a == '3') {
                    newNumber += '5'; // Replacing '3' with '5'
                    f = true;
                } else if (a == '5') {
                    newNumber += '7'; // Replacing '5' with '7'
                    f = true;
                } else {
                    newNumber += '3'; // Replacing other digits with '3'
                }
            }
        }
        if (!f) newNumber += '3'; // Appending '3' if no replacements were made

        // Reversing the new number and converting it back to a long
        reverse(newNumber.begin(), newNumber.end());
        i = stoll(newNumber); // Converting the string back to a long
    }

    // Output the result
    cout << c << endl; // Printing the count of valid numbers
    return 0; // Indicating successful completion
}

// <END-OF-CODE>
