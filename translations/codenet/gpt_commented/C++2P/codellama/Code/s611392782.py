# ACM-ICPCアジア地区予選2014 B. Miscalculation

# Function to perform multiplication based on the custom operator '*' in the string
def mul(str, idx):
    # Initialize result with the first digit
    res = int(str[idx])
    # Loop through the string to find '*' operators and perform multiplication
    while idx+1 < len(str) and str[idx+1]=='*':
        idx += 2 # Move index to the next number after '*'
        res *= int(str[idx]) # Multiply the result with the next number
    return res # Return the final multiplication result

# Function to perform addition based on the custom operator '+' in the string
def add(str, idx):
    # Start with the first multiplication result
    res = mul(str, idx)
    # Loop through the string to find '+' operators and perform addition
    while idx+1 < len(str) and str[idx+1] == '+':
        idx += 2 # Move index to the next number after '+'
        res += mul(str, idx) # Add the next multiplication result to the total
    return res # Return the final addition result

# Function to calculate the result based on Bob's interpretation of the expression
def bob(str, idx):
    # Initialize result with the first digit
    res = int(str[idx])
    # Loop through the string to evaluate the expression according to Bob's rules
    while idx+1 < len(str):
        # Check if the next operator is '+' or '*' and perform the corresponding operation
        if str[idx+1] == '+':
            res += int(str[idx+2]) # Add the next number
        else:
            res *= int(str[idx+2]) # Multiply by the next number
        idx += 2 # Move index to the next operator
    return res # Return the final result according to Bob's interpretation

# Read input until end of file
while True:
    try:
        s, d = input().split() # Read input
        idx = 0 # Initialize index for parsing the string
        a = add(s, idx) # Calculate the result using the addition function
        idx = 0 # Reset index for Bob's calculation
        b = bob(s, idx) # Calculate the result using Bob's interpretation
        # Compare results and print the corresponding output
        if a == int(d):
            print("U" if b == int(d) else "M") # Output 'U' if both are equal, else 'M'
        else:
            print("L" if b == int(d) else "I") # Output 'L' if Bob's result is equal, else 'I'
    except:
        break # Break out of loop when end of file is reached

