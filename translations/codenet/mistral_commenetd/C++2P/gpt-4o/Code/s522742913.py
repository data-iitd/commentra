import sys

# Initialize an empty string variable named 'source'
source = ""

# Read a string input from the standard input stream (sys.stdin) and store it in the 'source' variable
source = input()

# Check if the length of the input string is valid (greater than 10 characters or less than 1 character)
if len(source) > 10 or len(source) < 1:
    # If the condition is true, return an error code (-1)
    sys.exit(-1)

# Calculate the maximum value of 'i' based on the length of the input string using bitwise operations
max_i = 2 ** (len(source) - 1)

# Initialize a variable named 'sum' with a value of 0
total_sum = 0.0

# Iterate through the range of 'i' from 0 to 'max_i' using a for loop
for i in range(max_i):
    # Create a binary representation of 'i'
    plus = bin(i)[2:].zfill(len(source))  # Get binary string and pad with zeros

    # Initialize a variable named 'number' with a value of 0
    number = 0.0

    # Initialize a string variable named 'working' with the value of the input string 'source'
    working = source

    # Iterate through the bits of the 'plus' string from the least significant bit to the most significant bit
    while '1' in plus:
        # Find the index of the first '1' bit in the 'plus' string
        index = plus.index('1')

        # Add the substring of the 'working' string starting from the first '1' bit index to the 'total_sum' variable
        total_sum += float(working[:index + 1])

        # Shift the 'plus' string to the right by the index of the first '1' bit
        plus = plus[index + 1:]

        # Update the value of the 'working' string by removing the substring that has been added to the 'total_sum' variable
        working = working[index + 1:]

    # Add the remaining substring of the 'working' string to the 'total_sum' variable
    total_sum += float(working)

# Print the value of the 'total_sum' variable to the standard output stream (print) with no decimal places
print(f"{total_sum:.0f}")

# End of the program
# <END-OF-CODE>
