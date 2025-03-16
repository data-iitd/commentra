# Declare variables to hold two integers and a character for the operation
while True:
    # Read two integers and an operator from the user
    a, S, b = input().split()
    a = int(a)
    b = int(b)

    # Perform addition if the operator is '+'
    if S == '+':
        print(a + b)

    # Perform subtraction if the operator is '-'
    elif S == '-':
        print(a - b)

    # Perform multiplication if the operator is '*'
    elif S == '*':
        print(a * b)

    # Perform division if the operator is '/'
    elif S == '/':
        print(a / b)

    # Exit the loop if the operator is '?'
    elif S == '?':
        break

# <END-OF-CODE>
