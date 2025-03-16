
# Python 2.7.6
# Author: <NAME>
# Email: <EMAIL>
# Date: 2014-09-29
# Version: 1.0

# Function to perform multiplication based on the custom operator '*' in the string
def mul(str, idx):
    # Initialize result with the first digit
    res = str[idx]-'0'
    # Loop through the string to find '*' operators and perform multiplication
    while(idx+1 < len(str) and str[idx+1]=='*'):
        idx += 2 # Move index to the next number after '*'
        res *= str[idx]-'0' # Multiply the result with the next number
    return res # Return the final multiplication result

# Function to perform addition based on the custom operator '+' in the string
def add(str, idx):
    # Start with the first multiplication result
    res = mul(str, idx)
    # Loop through the string to find '+' operators and perform addition
    while(idx+1 < len(str) and str[idx+1] == '+'):
        idx += 2 # Move index to the next number after '+'
        res += mul(str, idx) # Add the next multiplication result to the total
    return res # Return the final addition result

# Function to calculate the result based on Bob's interpretation of the expression
def bob(str, idx):
    # Initialize result with the first digit
    res = str[idx]-'0'
    # Loop through the string to evaluate the expression according to Bob's rules
    while(idx+1 < len(str)):
        # Check if the next operator is '+' or '*' and perform the corresponding operation
        if(str[idx+1] == '+') 
            res += str[idx+2]-'0' # Add the next number
        else                  
            res *= str[idx+2]-'0' # Multiply by the next number
        idx += 2 # Move index to the next operator
    return res # Return the final result according to Bob's interpretation

# Read input until end of file
while True:
    s = raw_input()
    if s == "