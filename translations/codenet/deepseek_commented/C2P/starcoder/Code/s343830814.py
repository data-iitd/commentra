# Step 1: Import the necessary libraries
import sys

# Step 2: Read input from stdin
buf = sys.stdin.read()

# Step 3: Calculate the length of the input
len = len(buf)

# Step 4: Print the first character, the length minus 3, and the second last character of the input
print(buf[0], len-3, buf[len-2])

# Step 5: Return 0 to indicate successful execution
sys.exit(0)

