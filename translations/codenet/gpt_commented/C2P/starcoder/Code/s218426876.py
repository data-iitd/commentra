# <START-OF-CODE>

# Declare variables for iteration, sum, and a flag
i = 0
sum = 0
flag = 0 # Note: 'flag' is declared but not used in this code
x = [0] * 1002 # Array to store input strings

# Read the first input string
x = input()

# Loop to process input until the termination condition is met
while x[0]!= '0':
    # Iterate through the characters of the input string
    for i in range(0, 1002):
        # Check for the end of the string (null character)
        if x[i] == '\0':
            # Print the sum of the digits in the string
            print(sum)
            break # Exit the loop if end of string is reached
        else:
            # Convert character to integer and add to sum
            sum += ord(x[i]) - 0x30 # '0' is represented by 0x30 in ASCII
    # Reset sum for the next input
    sum = 0
    # Read the next input string
    x = input()

# 