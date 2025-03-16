#include <stdio.h>
#include <ctype.h>

# Initialize an integer variable 'i'
i = 0

# Initialize an integer array 'alpha' of size 26
alpha = [0] * 26

# Initialize a character variable 'ch'
ch = ''

# Start an infinite loop
while True:
    # Read a character from the standard input
    ch = input()

    # If the character read is End-Of-File (EOF), break the loop
    if ch == EOF:
        break

    # If the character is an alphabetic character
    if isalpha(ch):
        # If the character is an uppercase letter, increment the corresponding element in the array 'alpha'
        if isupper(ch):
            alpha[ch - 65] += 1

        # If the character is a lowercase letter, increment the corresponding element in the array 'alpha'
        else:
            alpha[ch - 97] += 1

# Initialize the character 'ch' with the ASCII value of 'a'
ch = 'a'

# Print the count of each alphabetic character and its corresponding ASCII value
for i in range(26):
    print(ch, alpha[i])
    ch += 1

# End of code
