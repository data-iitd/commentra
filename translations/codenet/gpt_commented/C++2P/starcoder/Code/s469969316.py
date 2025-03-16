# Define a function to compute the NOT operation
def Not(x):
    return 2 - x

# Define a function to compute the AND operation
def And(x, y):
    if x * y == 0: return 0
    if x == 2 and y == 2: return 2
    return 1

# Define a function to compute the OR operation
def Or(x, y):
    if x == 2 or y == 2: return 2
    if x == 1 or y == 1: return 1
    return 0

# Define a function to parse the expression and evaluate it
def parse():
    c = ss[it] # Get the current character from the string
    if '0' <= c and c <= '2': return c - '0' # Return the numeric value if it's a digit
    if c == '-': return Not(parse()) # Handle NOT operation

    # Parse left operand
    x = parse()
    c = ss[it + 1] # Get the operator
    # Parse right operand
    y = parse()
    it += 2 # Move past the closing parenthesis
    # Return the result of the operation based on the operator
    return c == '*' and And(x, y) or Or(x, y)

# Main function to read input and evaluate expressions
while True:
    input = raw_input() # Read the input
    if input == ".": break # Exit if the input is a single dot (.)
    a = [0, 0, 0] # Initialize the truth values for P, Q, R
    cnt = 0 # Initialize the count of valid evaluations

    # Iterate through all combinations of truth values for P, Q, R
    for i in range(3):
        for j in range(3):
            for k in range(3):
                a[0] = i; a[1] = j; a[2] = k # Assign truth values to P, Q, R
                ss = input # Copy the input expression for processing

                # Replace variables P, Q, R in the expression with their truth values
                for c in ss:
                    if c == 'P': c = a[0] + '0' # Replace P with its truth value
                    if c == 'Q': c = a[1] + '0' # Replace Q with its truth value
                    if c == 'R': c = a[2] + '0' # Replace R with its truth value

                it = 0 # Reset the index for parsing
                # Evaluate the expression and count if it evaluates to true (2)
                if parse() == 2: cnt += 1

    # Output the count of valid evaluations
    print cnt

