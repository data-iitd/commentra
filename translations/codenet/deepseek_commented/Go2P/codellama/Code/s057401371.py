
import sys

# Define the difference between lowercase and uppercase ASCII values
d = ord('a') - ord('A')

# Iterate over each character in the input string
for r in sys.stdin.readline():
    rr = r
    # Check if the character is an uppercase letter
    if ord('A') <= ord(r) <= ord('Z'):
        # Convert uppercase to lowercase
        rr = chr(ord(r) + d)
    elif ord('a') <= ord(r) <= ord('z'):
        # Convert lowercase to uppercase
        rr = chr(ord(r) - d)
    # Print the converted character
    print(rr, end='')

# 