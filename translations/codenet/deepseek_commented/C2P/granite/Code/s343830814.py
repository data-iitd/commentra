
import sys

# Step 1: Read input from stdin
buf = sys.stdin.readline()

# Step 2: Remove the trailing newline character from the input
buf = buf.rstrip('\n')

# Step 3: Calculate the length of the input
len = len(buf)

# Step 4: Print the first character, the length minus 3, and the second last character of the input
print(buf[0], len-3, buf[-2], sep='')

# Step 5: Return 0 to indicate successful execution
sys.exit(0)

