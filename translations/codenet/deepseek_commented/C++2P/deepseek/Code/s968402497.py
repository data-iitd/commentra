import sys

# Define constants for modular arithmetic
mod = 1000000007
mod9 = 998244353

# Define long double for high precision calculations
ld = float

# Define unsigned long long for large integers
ull = int

# Define double for floating point numbers
db = float

# Define long long for large integers
ll = int

# Define a small constant for precision in floating point comparisons
eps = 1e-7

# Define a macro for a for loop
def rep(i, be, en):
    for i in range(be, en + 1):
        yield i

# Define a macro for a reverse for loop
def per(i, be, en):
    for i in range(en, be - 1, -1):
        yield i

# The main function
def main():
    # Read three integers from standard input
    tc, n, m = map(int, sys.stdin.readline().split())
    
    # Swap n and m if n is greater than m
    if n > m:
        n, m = m, n
    
    # Iterate from 1 to m
    for i in range(1, m + 1):
        # Check if the product of i and tc is between n and m
        if i * tc >= n and i * tc <= m:
            print("OK")  # Print "OK" if the condition is met
            return  # Exit the function
    
    # Print "NG" if the condition is not met
    print("NG")

# Call the main function
main()

# End-of-code
