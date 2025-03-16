#include <stdio.h>

# Array to hold the count of each letter (a-z)
c = [0] * 26

def main():
    # Read strings from standard input until EOF
    while True:
        # Declare a string to hold the input
        str = input()

        # Check if EOF has been reached
        if str == "":
            break

        # Iterate through each character in the string
        for p in str:
            # Check if the character is a lowercase letter
            if 'a' <= p and p <= 'z':
                # Increment the count for the corresponding letter
                c[ord(p) - ord('a')] += 1
            # Check if the character is an uppercase letter
            elif 'A' <= p and p <= 'Z':
                # Increment the count for the corresponding letter (converted to lowercase)
                c[ord(p) - ord('A')] += 1

    # Print the count of each letter from 'a' to 'z'
    for i in range(26):
        print(chr(ord('a') + i), ':', c[i])

if __name__ == "__main__":
    main()

# 