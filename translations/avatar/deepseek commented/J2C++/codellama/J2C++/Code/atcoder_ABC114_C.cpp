#include <iostream>
#include <string>

using namespace std;

int main() {
    int N; // Declaring an integer N to read input
    cin >> N; // Reading an integer N from the user
    long i = 357; // Initializing the starting number
    int c = 0; // Initializing the counter for valid numbers

    // Main loop to find numbers containing '3', '5', and '7'
    while (i <= N) {
        string s = to_string(i); // Converting the current number to a string
        if (s.find("3") != string::npos && s.find("5") != string::npos && s.find("7") != string::npos) {
            c++; // Incrementing the counter if all required digits are present
        }

        // Building a new number by replacing the last digit
        string sb = "";
        bool f = false;
        for (int j = 0; j < s.length(); j++) {
            char a = s[s.length() - 1 - j];
            if (f) {
                sb += a; // Appending characters after the replacement
            } else {
                if (a == '3') {
                    sb += '5'; // Replacing '3' with '5'
                    f = true;
                } else if (a == '5') {
                    sb += '7'; // Replacing '5' with '7'
                    f = true;
                } else {
                    sb += '3'; // Replacing other digits with '3'
                }
            }
        }
        if (!f) sb += '3'; // Appending '3' if no replacements were made

        // Reversing the new number and converting it back to a long
        string sb2 = "";
        for (int j = sb.length() - 1; j >= 0; j--) {
            sb2 += sb[j];
        }
        i = stol(sb2);
    }

    // Output the result
    cout << c << endl; // Printing the count of valid numbers

    return 0;
}

