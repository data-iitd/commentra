
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // Read input from the user and convert it to a string
    string str;
    getline(cin, str);

    // Initialize variable to store the index of the decimal point
    int dotIndex = 0;

    // Find the index of the decimal point in the input
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            dotIndex = i;
            break;
        }
    }

    // Check if the digit before the decimal point is '9'
    if (str[dotIndex - 1] == '9') {
        // If it is, print a specific message
        cout << "GOTO Vasilisa." << endl;
    }
    // Check if the digit after the decimal point is greater than 4
    else if (str[dotIndex + 1] - '0' > 4) {
        // If it is, create a new string from the integer part and add 1
        string _str = "";
        for (int i = 0; i < dotIndex; i++)
            _str += str[i];
        // Print the incremented value
        cout << stoi(_str) + 1 << endl;
    }
    // If the digit after the decimal point is 4 or less
    else {
        // Print the integer part as it is
        for (int i = 0; i < dotIndex; i++)
            cout << str[i];
        cout << endl;
    }

    return 0;
}
