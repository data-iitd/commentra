

# Initialize scanner to read input from standard input
number = int(input())

# Initialize variables for answer and current value
ans = -1
value = 0

# Initialize mask variable for binary number manipulation
mask = 2

# Main loop to find the answer
while value < number:
    # Convert mask to binary string and remove leading '1'
    s = bin(mask)[2:]
    s = s[1:] if s[0] == '1' else s

    # Count the number of zeros in the binary string
    zeros = s.count('0')

    # If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
    if zeros!= len(s) - zeros: continue

    # Replace all zeros with '4' and all ones with '7' in the binary string
    s = s.replace('0', '4').replace('1', '7')

    # Convert the modified binary string back to a long number and update the value variable
    value = int(s)

# Print the answer
print(value)

