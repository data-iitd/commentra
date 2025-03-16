
# Python code to perform the same operations as the given C code

# Infinite loop to continuously read input until a termination condition is met
while True:
    # Read two integers and an operator from the user
    a = int(input("Enter first number: "))
    m = input("Enter operator (+, -, *, /, or?): ")
    b = int(input("Enter second number: "))
    
    # Check if the operator is '?' to terminate the loop
    if m == '?':
        break # Exit the loop if the termination operator is encountered
    
    # Perform addition if the operator is '+'
    if m == '+':
        c = a + b # Store the result of addition in the variable c
    # Perform subtraction if the operator is '-'
    elif m == '-':
        c = a - b # Store the result of subtraction in the variable c
    # Perform multiplication if the operator is '*'
    elif m == '*':
        c = a * b # Store the result of multiplication in the variable c
    # Perform division if the operator is '/'
    elif m == '/':
        c = a / b # Store the result of division in the variable c
    
    # Print the result
    print(c)

