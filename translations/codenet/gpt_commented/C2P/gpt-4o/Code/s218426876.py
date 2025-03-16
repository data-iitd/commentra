# Declare a variable for sum
sum = 0

# Read the first input string
x = input()

# Loop to process input until the termination condition is met
while x[0] != '0':  # Continue until the first character is '0'
    # Iterate through the characters of the input string
    for char in x:
        # Convert character to integer and add to sum
        sum += int(char)  # Convert character to integer and add to sum

    # Print the sum of the digits in the string
    print(sum)

    # Reset sum for the next input
    sum = 0

    # Read the next input string
    x = input()

# End of program
# <END-OF-CODE>
