# Get two integers from user input, separated by a space
a, b = map(int, input().split())

# Initialize the variable 'hole' to 1
hole = 1

# Initialize the variable 'i' to 0
i = 0

# Initialize the variable 'check' to True
check = True

# Loop until the condition is not met
while check:
    # Check if the value of 'hole' is greater than or equal to 'b'
    if hole >= b:
        # If the condition is met, set 'check' to False to terminate the loop
        check = False
    else:
        # If the condition is not met, update the value of 'hole'
        hole = a * (i + 1) - i
        # Increment the value of 'i' by 1
        i += 1

# Once the loop terminates, print out the value of 'i' as the result
print(i)
