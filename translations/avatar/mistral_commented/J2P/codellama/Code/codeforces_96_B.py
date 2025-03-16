
import sys

# Initialize scanner to read input from standard input
in = sys.stdin

# Read a long number as input
number = in.readline()

# Initialize variables for answer and current value
ans = -1
value = 0

# Initialize mask variable for binary number manipulation
mask = 2

# Main loop to find the answer
while value < number:
    # Convert mask to binary string and remove leading '1'
    s = bin(mask)[2:]

    # Count the number of zeros in the binary string
    zeros = 0
    for c in s:
        if c == '0':
            zeros += 1

    # If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
    if zeros != len(s) - zeros:
        mask += 1
        continue

    # Replace all zeros with '4' and all ones with '7' in the binary string
    s = s.replace('0', '4').replace('1', '7')

    # Convert the modified binary string back to a long number and update the value variable
    value = int(s, 2)

# Print the answer
print(value)

