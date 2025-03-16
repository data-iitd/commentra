# Define constants
mod = 1000000007  # Define a large prime number for modulo operations
mod9 = 998244353  # Another large prime number for modulo operations
eps = 1e-7  # Define a small epsilon value for floating-point comparisons
INF = float('inf')  # Define a large integer value for infinity

# Read the number of test cases, and two integers n and m
tc, n, m = map(int, input().split())

# Ensure n is the smaller of the two integers
if n > m:
    n, m = m, n

fl = 0  # Flag to indicate success

# Loop through the range from 1 to m
for i in range(1, m + 1):
    # Check if the current value multiplied by tc is within the range [n, m]
    if i * tc >= n and i * tc <= m:
        print("OK")  # Print "OK" if the condition is satisfied
        fl = 1  # Set the flag to indicate success
        break  # Exit the loop as we found a valid case

# If no valid case was found, print "NG"
if fl == 0:
    print("NG")

# End of code
# <END-OF-CODE>
