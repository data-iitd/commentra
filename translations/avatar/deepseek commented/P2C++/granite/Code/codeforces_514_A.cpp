

#include <iostream>
#include <string>
using namespace std;

int main() {
    string ip;
    cin >> ip;  // Taking an input from the user and storing it in the variable `ip`.
    string st = "";  // Initializing an empty string `st`.
    if (ip.length()!= 1) {  // Checking if the length of the input `ip` is not equal to 1.
        if (ip[0] == '9') {  // Checking if the first character of `ip` is "9".
            st = "9";  // Assigning "9" to `st`.
            ip = ip.substr(1);  // Removing the first character from `ip`.
        }
        for (int i = 0; i < ip.length(); i++) {  // Iterating over the remaining characters in `ip`.
            if (ip[i] - '0' > 4) {  // Checking if the integer value of the character is greater than 4.
                int n = 9 - (ip[i] - '0');  // Calculating the difference between 9 and the integer value.
                st += to_string(n);  // Converting it to a string and appending it to `st`.
            } else {  // If the integer value is not greater than 4.
                st += ip[i];  // Simply appending the character to `st`.
            }
        }
    } else {  // If the length of `ip` is 1.
        st = ip;  // Assigning `ip` directly to `st`.
    }
    cout << stoi(st);  // Printing the integer value of `st`.
    return 0;
}
