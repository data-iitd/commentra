
#include <stdio.h>

# Initialize an array 'c' of size 26 to store the count of each character.
c = [0] * 26

def main():
    str = "" # Declare a character array 'str' of size 1200 to store the input string.

    # Use a loop to read strings from the standard input using scanf() until the end of file is reached.
    while True:
        # Use a try-except block to handle the EOF error.
        try:
            str = input()
        except EOFError:
            break

        # Initialize a pointer 'p' to traverse the string 'str'.
        for p in str:
            # Use nested if conditions to check if the current character is a lowercase or uppercase letter.
            if 'a' <= p <= 'z':
                # Increment the count of the corresponding character in the 'c' array.
                c[ord(p) - ord('a')] += 1
            elif 'A' <= p <= 'Z':
                # Increment the count of the corresponding character in the 'c' array.
                c[ord(p) - ord('A')] += 1

    # Use a loop to print the count of each character and its corresponding character.
    for i in range(26):
        print(chr(ord('a') + i), ":", c[i])

    # Return 0 to indicate successful execution of the program.
    return 0

if __name__ == "__main__":
    main()

