#######
# Code
#######

# Take an integer input from the user
t = int(input())

# Define a function named 'solve' that takes an integer argument 'n'
def solve(n):
    # Calculate the sum of first 'n' natural numbers using the formula
    s = (1 + n) * n // 2
    
    # Initialize the variable 't' with the value 1
    t = 1
    
    # Run the while loop as long as 't' is less than or equal to 'n'
    while t <= n:
        # Subtract the contribution of 't' from the sum 's'
        s -= 2 * t
        
        # Multiply the value of 't' by 2 and update its value
        t *= 2
    
    # Return the final value of 's'
    return s

# Run the loop 't' number of times
for _ in range(t):
    # Take an integer input from the user for 'n'
    n = int(input())
    
    # Call the 'solve' function with the input 'n' and print the result
    print(solve(n))
