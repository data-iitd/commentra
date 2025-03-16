# The main function is the entry point of the program
while True:  # A while loop that runs indefinitely until the user enters '?' to exit
    user_input = input()  # Read a line of input from the user
    a, S, b = user_input.split()  # Split the input into components
    a = int(a)  # Convert 'a' to an integer
    b = int(b)  # Convert 'b' to an integer

    # Perform arithmetic operations based on the operator 'S'
    if S == '+':
        print(a + b)  # If 'S' is '+', print the sum of 'a' and 'b'
    elif S == '-':
        print(a - b)  # If 'S' is '-', print the difference of 'a' and 'b'
    elif S == '*':
        print(a * b)  # If 'S' is '*', print the product of 'a' and 'b'
    elif S == '/':
        print(a / b)  # If 'S' is '/', print the quotient of 'a' and 'b'
    elif S == '?':
        break  # If 'S' is '?', break out of the loop

# <END-OF-CODE>
