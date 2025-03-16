#include <iostream>  // Include the standard input/output stream library

int main()
{
    std::string n;  // Declare a string to store the input string
    std::cin >> n;  // Read a string from the user input and store it in the string n

    // Check if any two consecutive characters in the string n are the same
    if ((n[0] == n[1] && n[1] == n[2]) || (n[1] == n[2] && n[2] == n[3]))
    {
        std::cout << "Yes" << std::endl;  // Print "Yes" if the condition is true
    }
    else
    {
        std::cout << "No" << std::endl;  // Print "No" if the condition is false
    }

    return 0;  // Return 0 to indicate successful execution
}
