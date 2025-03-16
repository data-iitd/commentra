#include <stdio.h>
#include <string.h>

int main()
{
    # Declare a character array to hold the input string with a maximum length of 100 characters
    mes = input("Enter a string: ")

    # Print the first character of the string, the length of the string minus 2, and the last character of the string
    print(mes[0], len(mes) - 2, mes[len(mes) - 1])

    # Return 0 to indicate successful completion of the program
    return 0
}

