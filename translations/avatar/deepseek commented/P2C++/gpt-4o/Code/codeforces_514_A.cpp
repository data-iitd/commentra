#include <iostream>
#include <string>

int main() {
    std::string ip;  // Taking an input from the user and storing it in the variable `ip`.
    std::cin >> ip;  // Input from the user.
    std::string st = "";  // Initializing an empty string `st`.

    if (ip.length() != 1) {  // Checking if the length of the input `ip` is not equal to 1.
        if (ip[0] == '9') {  // Checking if the first character of `ip` is "9".
            st = "9";  // Assigning "9" to `st`.
            ip = ip.substr(1);  // Removing the first character from `ip`.
        }
        for (char i : ip) {  // Iterating over the remaining characters in `ip`.
            if (i > '4') {  // Checking if the character is greater than '4'.
                int n = 9 - (i - '0');  // Calculating the difference between 9 and the integer value.
                st += std::to_string(n);  // Converting it to a string and appending it to `st`.
            } else {  // If the character is not greater than '4'.
                st += i;  // Simply appending the character to `st`.
            }
        }
    } else {  // If the length of `ip` is 1.
        st = ip;  // Assigning `ip` directly to `st`.
    }
    
    std::cout << std::stoi(st) << std::endl;  // Printing the integer value of `st`.
    return 0;
}  // <END-OF-CODE>
