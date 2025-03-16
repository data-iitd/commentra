# <START-OF-CODE>

# Infinite loop to continuously read input until a termination condition is met
while True:
    # Read two integers and an operator from the user
    a, m, b = map(int, input().split())
    
    # Check if the operator is '?' to terminate the loop
    if m == '?':
        break # Exit the loop if the termination operator is encountered
    
    # Perform addition if the operator is '+'
    if m == '+':
        c = a + b # Store the result of addition in the results array
    
    # Perform subtraction if the operator is '-'
    if m == '-':
        c = a - b # Store the result of subtraction in the results array
    
    # Perform multiplication if the operator is '*'
    if m == '*':
        c = a * b # Store the result of multiplication in the results array
    
    # Perform division if the operator is '/'
    if m == '/':
        c = a / b # Store the result of division in the results array
    
    # Print all results stored in the results array
    print(c) # Output each result on a new line

# 