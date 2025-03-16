# Read the number of test cases
t = int(input())

# Define a function to solve the problem for a given n
def solve(n):
    # Calculate the sum of the first n natural numbers using the formula n(n + 1) / 2
    s = (1 + n) * n // 2
    
    # Initialize a variable to track the power of 2
    t = 1
    
    # Subtract twice the value of powers of 2 from the sum until t exceeds n
    while t <= n:
        s -= 2 * t  # Subtract 2 times the current power of 2 from the sum
        t *= 2      # Move to the next power of 2
    
    # Return the final computed sum
    return s

# Loop over each test case
for _ in range(t):
    # Read the input value for n
    n = int(input())
    
    # Print the result of the solve function for the current n
    print(solve(n))
