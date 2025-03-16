# Import iostream library for input and output operations
# Import string library for handling strings

def check(x, y): # Function declaration: check takes two integer arguments and returns a string
    if y % 2 == 0: # Check if y is even
        t = int(0.5*y) - x # Calculate t as half of y minus x

        if t >= 0 and (x-t) >= 0: # Check if t is greater than or equal to zero and if x - t is also greater than or equal to zero
            return "Yes" # If both conditions are true, return "Yes"
    return "No" # If y is not even, return "No"

x, y = map(int, input().split()) # Read input values for x and y from standard input

print(check(x, y)) # Call check function with input values and print its return value to standard output

# 