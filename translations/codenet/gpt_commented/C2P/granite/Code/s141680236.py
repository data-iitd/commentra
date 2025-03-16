
kinbo = [] # Initialize an empty list to serve as the stack

while True:
    try:
        null = input() # Read input from the user
    except EOFError:
        break # Exit the loop if EOF is encountered

    if null[0] == '+':
        chonda = kinbo.pop() # Pop the top two values from the stack
        yamagami = kinbo.pop()
        kinbo.append(chonda + yamagami) # Push the result of addition back onto the stack
    elif null[0] == '-':
        yamagami = kinbo.pop() # Pop the top two values from the stack
        chonda = kinbo.pop()
        kinbo.append(chonda - yamagami) # Push the result of subtraction back onto the stack
    elif null[0] == '*':
        chonda = kinbo.pop() # Pop the top two values from the stack
        yamagami = kinbo.pop()
        kinbo.append(chonda * yamagami) # Push the result of multiplication back onto the stack
    else:
        kinbo.append(int(null)) # Convert the input to an integer and push onto the stack

print(kinbo.pop()) # Pop and print the final result from the stack

