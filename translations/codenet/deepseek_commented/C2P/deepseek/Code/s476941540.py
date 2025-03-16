import sys

# Initialize the alpha array to zero for all elements
alpha = [0] * 26

# Read characters from the standard input until EOF
for line in sys.stdin:
    for ch in line:
        # Check if the character is an alphabetic character
        if ch.isalpha():
            # Increment the corresponding element in alpha based on case
            if ch.isupper():
                alpha[ord(ch) - ord('A')] += 1
            else:
                alpha[ord(ch) - ord('a')] += 1

# Print the counts of each letter from 'a' to 'z'
for i in range(26):
    print(f"{chr(i + ord('a'))} : {alpha[i]}")
