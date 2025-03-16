
# Declare and initialize variables 'a' and 'b' to store user input
a = int(input())
b = int(input())

# Declare variable 'result' to store the result of the computation
result = 0

# Check if 'a' is greater than 'b'
if a > b:
    # If true, assign the value '2 * a - 1' to 'result'
    result = 2 * a - 1

# Check if 'a' is equal to 'b'
elif a == b:
    # If true, assign the value '2 * a' to 'result'
    result = 2 * a

# If 'a' is less than 'b'
else:
    # Assign the value '2 * b - 1' to 'result'
    result = 2 * b - 1

# Print the value of 'result' to the console
print(result)

# Terminate the program with a return value of 0
