#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaring the main method

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Declaring necessary I/O objects

    string s;
    cin >> s;
    // Reading the first line of input as a string and storing it in the's' variable

    int n = s.length();
    // Declaring and initializing the length of the string's' in the variable 'n'

    int k;
    cin >> k;
    // Reading the second line of input as an integer and storing it in the variable 'k'

    int res = 0;
    // Declaring and initializing an integer variable'res' to store the result

    for (int i = 0; i < k; i++) {
        // Starting a for loop that iterates 'k' times

        string input;
        cin >> input;
        // Reading a string as input and storing it in the 'input' variable

        int a = 0;
        int b = 0;
        // Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the string's'

        for (int j = 0; j < n; j++) {
            // Starting a nested for loop that iterates through each index of the string's'

            if (s[j] == input[0])
                a++;  // Incrementing the 'a' variable if the character at the current index matches the first character of the input string

            else if (s[j] == input[1])
                b++;  // Incrementing the 'b' variable if the character at the current index matches the second character of the input string

            else {
                res += min(a, b);  // Adding the minimum of 'a' and 'b' to the'res' variable if the current character is different from both characters in the input string
                a = b = 0;  // Resetting the 'a' and 'b' variables to zero
            }
        }

        res += min(a, b);  // Adding the minimum of 'a' and 'b' to the'res' variable after the end of the outer for loop
    }

    cout << res << endl;
    // Printing the final result to the standard output stream

    return 0;
}

