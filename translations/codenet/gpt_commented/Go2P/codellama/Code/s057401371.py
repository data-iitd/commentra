
# Import the necessary modules
import sys

# Read the input text from standard input
s = sys.stdin.readline()

# Calculate the difference between lowercase and uppercase letters
d = ord('a') - ord('A')

# Iterate over each character in the input string
for r in s:
    # Initialize a variable to hold the modified character
    rr = r

    # Check if the character is an uppercase letter
    if 'A' <= r <= 'Z':
        # Convert uppercase to lowercase by adding the difference
        rr = chr(ord(r) + d)
    elif 'a' <= r <= 'z':
        # Convert lowercase to uppercase by subtracting the difference
        rr = chr(ord(r) - d)

    # Print the modified character
    print(rr, end='')

# Print a newline at the end of the output
print()

