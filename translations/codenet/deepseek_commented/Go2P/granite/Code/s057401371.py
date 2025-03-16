
import sys

# Define the difference between lowercase and uppercase ASCII values
d = ord('a') - ord('A')

# Iterate over each character in the input string
for c in sys.stdin.read():
    # Check if the character is an uppercase letter
    if ord('A') <= ord(c) <= ord('Z'):
        # Convert uppercase to lowercase
        c = chr(ord(c) + d)
    elif ord('a') <= ord(c) <= ord('z'):
        # Convert lowercase to uppercase
        c = chr(ord(c) - d)
    # Print the converted character
    sys.stdout.write(c)

# End of code
