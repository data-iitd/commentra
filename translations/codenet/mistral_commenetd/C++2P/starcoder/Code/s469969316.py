# Define a function to calculate NOT of a binary number
def Not(x):
    return 2-x

# Define a function to calculate AND of two binary numbers
def And(x, y):
    if x*y == 0: return 0 # If product of x and y is zero, return zero
    if x == 2 and y == 2: return 2 # If both x and y are 2, return 2
    return 1 # Otherwise, return 1

# Define a function to calculate OR of two binary numbers
def Or(x, y):
    if x == 2 or y == 2: return 2 # If either x or y is 2, return 2
    if x == 1 or y == 1: return 1 # If either x or y is 1, return 1
    return 0 # Otherwise, return 0

# Define a function to parse the input string and calculate the logical expression
def parse():
    c = ss[it] # Read the next character from the input string
    if '0' <= c and c <= '2': return ord(c)-ord('0') # If character is a binary digit, convert it to an integer and return
    if c == '-': return Not(parse()) # If character is NOT, recursively call parse() and apply NOT

    x = parse() # Parse the first binary number
    c = ss[it+1] # Read the next character from the input string
    y = parse() # Parse the second binary number
    it += 2 # Increment the index of the input string
    return And(x, y) if c == '*' else Or(x, y) # If character is AND, call And() function. Otherwise, call Or() function

# Main function
while True:
    input = input() # Read input until end of file is reached
    if input == '.': break # If end of file is reached, break
    a = [0, 1, 2] # Initialize the array a with values 0, 1, 2
    cnt = 0 # Initialize counter for counting the number of valid expressions
    for i in a:
        for j in a:
            for k in a:
                a[0] = i; a[1] = j; a[2] = k;
                ss = input # Set the input string for the current combination
                ss = ss.replace('P', str(a[0]))
                ss = ss.replace('Q', str(a[1]))
                ss = ss.replace('R', str(a[2]))
                it = 0 # Reset the index of the input string
                if parse() == 2: cnt += 1 # If the logical expression is valid, increment the counter
    print(cnt) # Print the number of valid expressions for the current input

