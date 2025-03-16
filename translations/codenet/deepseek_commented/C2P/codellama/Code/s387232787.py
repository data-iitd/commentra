#include <stdio.h>

# Array to store the count of each letter (a-z)
c = [0] * 26

def main():
    # Array to store the input string
    str = []
    
    # Read input strings until there are no more inputs
    while True:
        # Pointer to traverse the string
        p = 0
        
        # Traverse each character in the string
        for i in range(len(str)):
            # Check if the character is a lowercase letter
            if 'a' <= str[i] <= 'z':
                # Increment the count for the corresponding letter
                c[ord(str[i]) - ord('a')] += 1
            # Check if the character is an uppercase letter
            elif 'A' <= str[i] <= 'Z':
                # Increment the count for the corresponding letter
                c[ord(str[i]) - ord('A')] += 1
        # Read input strings until there are no more inputs
        str = input()
        if str == '':
            break
    
    # Print the counts for each letter from 'a' to 'z'
    for i in range(26):
        print(chr(ord('a') + i), ':', c[i])

if __name__ == '__main__':
    main()

