import sys
from functools import reduce

# Constants
MOD = 1000000007

# Function to read an integer from input
def scan_int():
    return int(sys.stdin.readline().strip())

# Function to read multiple integers from input
def scan_ints(n):
    return list(map(int, sys.stdin.readline().strip().split()))

# Function to perform modular exponentiation
def modpow(a, n):
    res = 1
    while n > 0:
        if n & 1:  # If n is odd
            res = res * a % MOD
        a = a * a % MOD  # Square the base
        n >>= 1  # Divide n by 2
    return res

# Main function where execution starts
def main():
    n = scan_int()  # Read the number of integers
    c = scan_ints(n)  # Read n integers into list c

    ans = 0  # Initialize answer variable
    c.sort()  # Sort the list of integers

    # Calculate the answer based on the sorted integers
    for i in range(n):
        ans = (ans + (n + 1 - i) * c[i] % MOD) % MOD  # Update the answer using the formula

    # Print the final result after applying modular exponentiation
    print(ans * modpow(4, n - 1) % MOD)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
