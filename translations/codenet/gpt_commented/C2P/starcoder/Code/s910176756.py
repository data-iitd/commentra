# <START-OF-CODE>

# Declare variables for two integers and one character operator
a, b, c = 0, 0, 0
op = ''

# Read input values: two integers and an operator
a, op, b = map(int, input().split())

# Start an infinite loop to continuously process operations
while True:
    # Check if the operator is addition
    if op == '+':
        c = a + b # Perform addition
        print(c) # Output the result
    # Check if the operator is subtraction
    elif op == '-':
        c = a - b # Perform subtraction
        print(c) # Output the result
    # Check if the operator is multiplication
    elif op == '*':
        c = a * b # Perform multiplication
        print(c) # Output the result
    # Check if the operator is division
    elif op == '/':
        c = a / b # Perform division
        print(c) # Output the result
    # If the operator is not recognized, exit the loop
    else:
        break # Exit the loop if an invalid operator is provided

    # Read the next set of inputs: two integers and an operator
    a, op, b = map(int, input().split())

# 