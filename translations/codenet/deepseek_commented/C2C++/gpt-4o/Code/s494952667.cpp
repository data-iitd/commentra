#include <iostream> // Include headers for input/output operations
#include <string>   // Include headers for string manipulation

int main()
{
    std::string str; // Declare a string to store the input
    std::cin >> str; // Read a string from the user

    // Reverse the string and print it
    for (int i = str.length() - 1; i >= 0; i--) {
        std::cout << str[i]; // Print each character in reverse order
    }
    std::cout << std::endl; // Print a newline character at the end

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
