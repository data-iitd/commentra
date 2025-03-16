#include <iostream>
#include <string>

int main() {
    // Create a variable to read input from the user
    long a;
    std::string b;

    // Read a long integer value from the user
    std::cin >> a;

    // Read a string value from the user
    std::cin >> b;

    // Initialize an empty string to build the integer representation
    std::string bStr;

    // Loop through each character in the string
    for (char c : b) {
        // If the character is not a '.', append it to bStr
        if (c != '.') {
            bStr += c;
        }
    }

    // Convert the built string (bStr) to an integer
    int bInt = std::stoi(bStr);

    // Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
    long result = (a * bInt) / 100;

    // Print the result to the console
    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
