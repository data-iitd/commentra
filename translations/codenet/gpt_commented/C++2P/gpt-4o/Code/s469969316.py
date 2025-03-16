def Not(x):
    return 2 - x  # Returns the negation of the input value

def And(x, y):
    if x * y == 0:
        return 0  # If either input is 0, return 0
    if x == 2 and y == 2:
        return 2  # If both inputs are 2, return 2
    return 1  # Otherwise, return 1

def Or(x, y):
    if x == 2 or y == 2:
        return 2  # If either input is 2, return 2
    if x == 1 or y == 1:
        return 1  # If either input is 1, return 1
    return 0  # Otherwise, return 0

def parse(ss, it):
    c = ss[it[0]]  # Get the current character from the string
    it[0] += 1  # Move to the next character
    if '0' <= c <= '2':
        return int(c)  # Return the numeric value if it's a digit
    if c == '-':
        return Not(parse(ss, it))  # Handle NOT operation

    # Parse left operand
    x = parse(ss, it)
    c = ss[it[0]]  # Get the operator
    it[0] += 1  # Move to the next character
    # Parse right operand
    y = parse(ss, it)
    it[0] += 1  # Move past the closing parenthesis
    # Return the result of the operation based on the operator
    return And(x, y) if c == '*' else Or(x, y)

def main():
    while True:
        input_expr = input()  # Read input
        if input_expr == ".":
            break  # Exit on single dot

        cnt = 0  # Initialize the count of valid evaluations

        # Iterate through all combinations of truth values for P, Q, R
        for i in range(3):
            for j in range(3):
                for k in range(3):
                    a = [i, j, k]  # Assign truth values to P, Q, R
                    ss = input_expr  # Copy the input expression for processing

                    # Replace variables P, Q, R in the expression with their truth values
                    ss = ss.replace('P', str(a[0]))
                    ss = ss.replace('Q', str(a[1]))
                    ss = ss.replace('R', str(a[2]))

                    it = [0]  # Reset the index for parsing
                    # Evaluate the expression and count if it evaluates to true (2)
                    if parse(ss, it) == 2:
                        cnt += 1

        # Output the count of valid evaluations
        print(cnt)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
