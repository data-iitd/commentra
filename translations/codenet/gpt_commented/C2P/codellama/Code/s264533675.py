#include <stdio.h>

int main() {
    # Declare a character array (string) of size 30 to hold user input
    str = input("Enter a string: ")

    # Replace the character at index 5 with a space
    str[5] = ' '

    # Replace the character at index 13 with a space
    str[13] = ' '

    # Print the modified string to the console
    print(str)

    # Return 0 to indicate successful execution of the program
    return 0
}
