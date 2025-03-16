
import sys

# Read the input text from standard input (sys.stdin)
s = sys.stdin.readline().rstrip()

# Calculate the difference between lowercase and uppercase letters
d = ord('a') - ord('A')

# Iterate over each character in the input string
for r in s:
    # Initialize a variable to hold the modified character
    rr = r
    
    # Check if the character is an uppercase letter
    if ord('A') <= ord(r) <= ord('Z'):
        # Convert uppercase to lowercase by adding the difference
        rr = chr(ord(r) + d)
    elif ord('a') <= ord(r) <= ord('z'):
        # Convert lowercase to uppercase by subtracting the difference
        rr = chr(ord(r) - d)
    
    # Print the modified character
    sys.stdout.write(rr)

# Print a newline at the end of the output
sys.stdout.write("\n")

