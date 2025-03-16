
# Python code to calculate the factorial of a number

# Read an integer value from the user and store it in 'n'
n = int(input("Enter a number: "))

# Initialize'm' with the value of 'n'
m = n

# Decrease 'n' by 1 to prepare for the factorial calculation
n -= 1

# Loop to calculate the factorial of 'n' (m = n!)
for n in range(n, 0, -1):
    # Multiply'm' by the current value of 'n'
    m *= n

# Print the calculated factorial value stored in'm'
print(m)

# End of Python code
