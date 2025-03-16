#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    # Declare a buffer to hold the input string and an integer to store its length
    buf = input("Enter a string: ")
    len = len(buf)

    # Print the first character, the length of the string minus 3, and the second to last character
    print(buf[0], len-3, buf[len-2])

    # Return 0 to indicate successful completion of the program
    return 0
}

