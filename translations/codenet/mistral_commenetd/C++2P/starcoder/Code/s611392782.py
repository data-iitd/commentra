# Python 2.7.6
# Author: <NAME>
# Email: <EMAIL>
# Date: 2014-09-15

# Function to calculate the multiplication part of the expression
def mul(str, idx):
    res = str[idx]-'0' # Extract the first digit and store it in'res'
    while(idx+1 < len(str) and str[idx+1]=='*'): # Check if there is a '*' symbol
        idx += 2 # Move the index to the next symbol
        res *= str[idx]-'0' # Multiply'res' with the next digit
    return res # Return the final result

# Function to calculate the addition part of the expression
def add(str, idx):
    res = mul(str, idx) # Call the'mul' function to calculate the multiplication part
    while(idx+1 < len(str) and str[idx+1] == '+'): # Check if there is a '+' symbol
        idx += 2 # Move the index to the next symbol
        res += mul(str, idx) # Add the result of the next multiplication part
    return res # Return the final result

# Function to calculate the whole expression
def bob(str, idx):
    res = str[idx]-'0' # Extract the first digit and store it in'res'
    while(idx+1 < len(str)): # Loop through the rest of the expression
        if(str[idx+1] == '+') res += str[idx+2]-'0' # If there is a '+' symbol, add the next digit
        else                  res *= str[idx+2]-'0' # If there is a '*' symbol, multiply the next digit
        idx += 2 # Move the index to the next symbol
    return res # Return the final result

while True:
    s = raw_input() # Read the input string from the standard input
    d = int(raw_input()) # Read the desired result from the standard input
    if s == "