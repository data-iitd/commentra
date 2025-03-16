# Define constants for modular arithmetic
mod = 1000000007
mod9 = 998244353
eps = 1e-7  # Define a small constant for precision in floating point comparisons

# Read three integers from standard input
tc, n, m = map(int, input().split())

# Swap n and m if n is greater than m
if n > m:
    n, m = m, n

fl = 0  # Initialize a flag

# Iterate from 1 to m
for i in range(1, m + 1):
    # Check if the product of i and tc is between n and m
    if i * tc >= n and i * tc <= m:
        print("OK")  # Print "OK" if the condition is met
        fl = 1  # Set the flag to true
        break  # Exit the loop

if fl == 0:
    print("NG")  # Print "NG" if the flag is still false after the loop

# End of the program
# <END-OF-CODE>
