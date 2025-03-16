import sys

# Initialize the alpha array to zero for all 26 letters of the alphabet
alpha = [0] * 26

# Read characters from standard input until EOF is encountered
for line in sys.stdin:
    for ch in line:
        # Check if the character is an alphabet letter
        if ch.isalpha():
            # If the character is uppercase, increment the corresponding index in the alpha array
            if ch.isupper():
                alpha[ord(ch) - ord('A')] += 1
            else:
                # If the character is lowercase, increment the corresponding index in the alpha array
                alpha[ord(ch) - ord('a')] += 1

# Print the count of each letter from 'a' to 'z'
for i in range(26):
    print(f"{chr(i + ord('a'))} : {alpha[i]}")
