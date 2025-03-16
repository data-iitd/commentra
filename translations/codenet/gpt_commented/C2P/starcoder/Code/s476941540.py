#include <stdio.h>
#include <ctype.h>

def main():
    # Declare variables: 'i' for loop control, 'alpha' array to count occurrences of each letter, and 'ch' for character input
    i = 0
    alpha = [0] * 26
    ch = ''

    # Initialize the alpha array to zero for all 26 letters of the alphabet
    for i in range(0, 26):
        alpha[i] = 0

    # Infinite loop to read characters until EOF (End of File) is encountered
    while(1):
        ch = input() # Read a character from standard input
        if(ch == ''): break # Exit the loop if EOF is reached

        # Check if the character is an alphabet letter
        if(ch.isalpha()):
            # If the character is uppercase, increment the corresponding index in the alpha array
            if(ch.isupper()):
                alpha[ord(ch) - ord('A')] += 1 # 'A' is at index 0, 'B' at index 1,..., 'Z' at index 25
            else:
                # If the character is lowercase, increment the corresponding index in the alpha array
                alpha[ord(ch) - ord('a')] += 1 # 'a' is at index 0, 'b' at index 1,..., 'z' at index 25

    # Print the count of each letter from 'a' to 'z'
    ch = 'a' # Start with the letter 'a'
    for i in range(0, 26):
        print(ch, ':', alpha[i]) # Output the letter and its count

main()

