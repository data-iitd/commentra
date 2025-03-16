#include <stdio.h>

# Declare a string to hold the input
str = ""

# Read strings from standard input until EOF
while scanf("%s", str) > 0:
    # Iterate through each character in the string
    for p in str:
        # Check if the character is a lowercase letter
        if 'a' <= p <= 'z':
            # Increment the count for the corresponding letter
            c[p - 'a'] += 1
        # Check if the character is an uppercase letter
        elif 'A' <= p <= 'Z':
            # Increment the count for the corresponding letter (converted to lowercase)
            c[p - 'A'] += 1

# Print the count of each letter from 'a' to 'z'
for i in range(26):
    print(chr(i + ord('a')), ':', c[i])

print("