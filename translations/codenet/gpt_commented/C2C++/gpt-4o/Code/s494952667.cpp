#include <iostream>
#include <cstring>

int main() {
    // Declare a character array to hold the input string (maximum length 20 + 1 for null terminator)
    char str[21];
    
    // Read a string from standard input
    std::cin >> str;
    
    // Calculate the length of the input string
    int len = std::strlen(str);

    // Loop through the string in reverse order
    for(int i = len - 1; i >= 0; i--) {
        // Output each character of the string in reverse
        std::putchar(str[i]);
    }
    
    // Print a newline character after the reversed string
    std::cout << std::endl;
    
    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
