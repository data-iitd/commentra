#include <iostream> // Including iostream for input and output
#include <string>   // Including string for string manipulation

using namespace std;

int main() {
    // Initializing variables
    long a; // Declaring long variable 'a'
    cin >> a; // Reading long value from the console and assigning it to 'a'

    string b; // Declaring string variable 'b'
    cin >> b; // Reading string value from the console and assigning it to 'b'

    string bStr = ""; // Initializing empty string variable 'bStr'
    for (char c : b) {
        // Loop to iterate through each character in string 'b'
        if (c != '.') {
            // If current character is not '.', add it to string 'bStr'
            bStr += c;
        }
    }

    int bInt; // Declaring integer variable 'bInt'
    bInt = stoi(bStr); // Converting string 'bStr' to integer and assigning it to 'bInt'

    long result; // Declaring long variable 'result'
    result = (a * bInt) / 100; // Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to 'result'

    cout << result << endl; // Printing the value of 'result' to the console

    return 0; // Returning 0 to indicate successful execution
} // End of main function
// <END-OF-CODE>
