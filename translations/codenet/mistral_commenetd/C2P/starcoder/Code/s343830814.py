#include <stdio.h>
#include <string.h>

# The main function is the entry point of the program
def main():
    # Declare a character array 'buf' of size 512
    buf = [None] * 512

    # Declare an integer variable 'len' to store the length of the string read
    len = 0

    # Read a line from standard input using fgets() and store it in 'buf'
    buf = fgets(buf, 512, stdin)

    # Calculate the length of the string read and store it in 'len'
    len = strlen(buf)

    # Print the first character of the string, its length (minus 3), and the last character of the string
    printf("%c%d%c\n", buf[0], len-3, buf[len-2])

    # Return 0 to indicate successful execution of the program
    return 0

# 