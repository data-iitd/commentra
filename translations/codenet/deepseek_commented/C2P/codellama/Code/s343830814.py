#include <stdio.h>  # Include headers for input/output operations
#include <string.h> # Include headers for string manipulation

def main(argc, argv):
    buf = [512]  # Define a character array to store the input
    len = 0      # Define an integer to store the length of the input

    # Step 3: Read input from stdin
    fgets(buf, sizeof(buf), stdin)

    # Step 4: Calculate the length of the input
    len = strlen(buf)

    # Step 5: Print the first character, the length minus 3, and the second last character of the input
    print(buf[0], len-3, buf[len-2])

    # Step 6: Return 0 to indicate successful execution
    return 0

