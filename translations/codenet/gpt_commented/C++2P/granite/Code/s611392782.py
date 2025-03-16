
# ACM-ICPCアジア地区予選2014 B. Miscalculation

def mul(s, idx):
    # Initialize result with the first digit
    res = int(s[idx])
    # Loop through the string to find '*' operators and perform multiplication
    while idx+1 < len(s) and s[idx+1]=='*':
        idx += 2 # Move index to the next number after '*'
        res *= int(s[idx]) # Multiply the result with the next number
    return res # Return the final multiplication result

def add(s, idx):
    # Start with the first multiplication result
    res = mul(s, idx)
    # Loop through the string to find '+' operators and perform addition
    while idx+1 < len(s) and s[idx+1] == '+':
        idx += 2 # Move index to the next number after '+'
        res += mul(s, idx) # Add the next multiplication result to the total
    return res # Return the final addition result

def bob(s, idx):
    # Initialize result with the first digit
    res = int(s[idx])
    # Loop through the string to evaluate the expression according to Bob's rules
    while idx+1 < len(s):
        # Check if the next operator is '+' or '*' and perform the corresponding operation
        if s[idx+1] == '+': 
            res += int(s[idx+2]) # Add the next number
        else:                  
            res *= int(s[idx+2]) # Multiply by the next number
        idx += 2 # Move index to the next operator
    return res # Return the final result according to Bob's interpretation

while True:
    try:
        s = input() # Read input string
        d = int(input()) # Read expected result
        idx = 0 # Initialize index for parsing the string
        a = add(s, idx) # Calculate the result using the addition function
        idx = 0 # Reset index for Bob's calculation
        b = bob(s, idx) # Calculate the result using Bob's interpretation
        # Compare results and print the corresponding output
        if a == d:
            print("U" if b == d else "M") # Output 'U' if both are equal, else 'M'
        else:
            print("L" if b == d else "I") # Output 'L' if Bob's result is equal, else 'I'
    except:
        break # Exit the loop when end of file is reached

