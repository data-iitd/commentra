#include <stdio.h>
#include <ctype.h>

def main():
    alpha = [0] * 26
    ch = ''

    # Initialize the alpha array to zero for all elements
    for i in range(26):
        alpha[i] = 0

    # Read characters from the standard input until EOF
    while True:
        ch = input()
        if ch == EOF:
            break

        # Check if the character is an alphabetic character
        if isalpha(ch):
            # Increment the corresponding element in alpha based on case
            if isupper(ch):
                alpha[ord(ch) - 65] += 1
            else:
                alpha[ord(ch) - 97] += 1

    # Print the counts of each letter from 'a' to 'z'
    ch = 'a'
    for i in range(26):
        print(ch, ':', alpha[i])
        ch = chr(ord(ch) + 1)

main()

