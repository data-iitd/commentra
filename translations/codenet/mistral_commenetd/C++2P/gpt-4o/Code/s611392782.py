def mul(s, idx):
    res = int(s[idx])  # Extract the first digit and store it in 'res'
    while idx + 1 < len(s) and s[idx + 1] == '*':  # Check if there is a '*' symbol
        idx += 2  # Move the index to the next symbol
        res *= int(s[idx])  # Multiply 'res' with the next digit
    return res  # Return the final result

def add(s, idx):
    res = mul(s, idx)  # Call the 'mul' function to calculate the multiplication part
    while idx + 1 < len(s) and s[idx + 1] == '+':  # Check if there is a '+' symbol
        idx += 2  # Move the index to the next symbol
        res += mul(s, idx)  # Add the result of the next multiplication part
    return res  # Return the final result

def bob(s, idx):
    res = int(s[idx])  # Extract the first digit and store it in 'res'
    while idx + 1 < len(s):  # Loop through the rest of the expression
        if s[idx + 1] == '+':
            res += int(s[idx + 2])  # If there is a '+' symbol, add the next digit
        else:
            res *= int(s[idx + 2])  # If there is a '*' symbol, multiply the next digit
        idx += 2  # Move the index to the next symbol
    return res  # Return the final result

if __name__ == "__main__":
    while True:
        try:
            s, d = input().split()  # Read the input string and desired result from the standard input
            d = int(d)  # Convert the desired result to an integer
            idx = 0  # Initialize the index to 0
            a = add(s, idx)  # Call the 'add' function to calculate the addition part of the expression
            idx = 0  # Reset the index to 0
            b = bob(s, idx)  # Call the 'bob' function to calculate the whole expression
            if a == d:  # Check if the addition part matches the desired result
                print("U" if b == d else "M")  # If both parts match, print 'U', otherwise print 'M'
            else:  # If the addition part doesn't match, check if the whole expression matches
                print("L" if b == d else "I")  # If the whole expression matches, print 'L', otherwise print 'I'
        except EOFError:
            break  # Exit the loop on end of input
# <END-OF-CODE>
