def Not(x):  # Function to calculate NOT of a binary number
    return 2 - x

def And(x, y):  # Function to calculate AND of two binary numbers
    if x * y == 0:
        return 0  # If product of x and y is zero, return zero
    if x == 2 and y == 2:
        return 2  # If both x and y are 2, return 2
    return 1  # Otherwise, return 1

def Or(x, y):  # Function to calculate OR of two binary numbers
    if x == 2 or y == 2:
        return 2  # If either x or y is 2, return 2
    if x == 1 or y == 1:
        return 1  # If either x or y is 1, return 1
    return 0  # Otherwise, return 0

def parse(ss, it):  # Function to parse the input string and calculate the logical expression
    c = ss[it[0]]  # Read the next character from the input string
    it[0] += 1  # Increment the index of the input string
    if '0' <= c <= '2':
        return int(c)  # If character is a binary digit, convert it to an integer and return
    if c == '-':
        return Not(parse(ss, it))  # If character is NOT, recursively call parse() and apply NOT

    x = parse(ss, it)  # Parse the first binary number
    c = ss[it[0]]  # Read the next character from the input string
    it[0] += 1  # Increment the index of the input string
    y = parse(ss, it)  # Parse the second binary number
    it[0] += 1  # Increment the index of the input string
    return And(x, y) if c == '*' else Or(x, y)  # If character is AND, call And() function. Otherwise, call Or() function

def main():
    while True:
        input_str = input()  # Read input
        if input_str == ".":
            break  # Stop if input is "."
        
        cnt = 0  # Initialize counter for counting the number of valid expressions
        for i in range(3):  # Loop for a
            for j in range(3):  # Loop for b
                for k in range(3):  # Loop for c
                    a = [i, j, k]  # Set the values of a, b, c
                    ss = input_str  # Set the input string for the current combination
                    ss = ss.replace('P', str(a[0])).replace('Q', str(a[1])).replace('R', str(a[2]))  # Replace P, Q, R with values
                    it = [0]  # Reset the index of the input string
                    if parse(ss, it) == 2:  # If the logical expression is valid, increment the counter
                        cnt += 1
        print(cnt)  # Print the number of valid expressions for the current input

if __name__ == "__main__":
    main()

# <END-OF-CODE>
