
#include <iostream> // Standard Input/Output Stream Library
#include <string> // String Library

int main()
{
    std::string str; // Declare and initialize a string variable named'str'
    std::cout << "Enter a string: "; // Prompt the user to enter a string
    std::cin >> str; // Read a string from the standard input and store it in the'str' variable

    std::cout << "Reversed string: "; // Print a message to indicate that the reversed string will be printed

    for(int i = str.length()-1; i >= 0; i--){ // Use a for loop to print each character of the string in reverse order
        std::cout << str[i]; // Print the character at the index 'i' of the'str' variable
    }

    std::cout << "\n"; // Print a newline character
    return 0; // Indicate successful execution
}

