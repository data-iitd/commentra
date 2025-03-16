import sys
from functools import reduce

# Constants
mod = 1000000007

# Function to read an integer from standard input
def scan_int():
    return int(sys.stdin.readline().strip())

# Function to read n integers from standard input
def scan_ints(n):
    return list(map(int, sys.stdin.readline().strip().split()))

# Function to calculate modular exponentiation
def modpow(a, n):
    res = 1
    while n > 0:
        if n % 2 == 1:
            res = res * a % mod
        a = a * a % mod
        n //= 2
    return res

# Main function
def main():
    n = scan_int()  # Read an integer n from standard input
    c = scan_ints(n)  # Read n integers c from standard input

    ans = 0  # Initialize answer variable to 0
    c.sort()  # Sort list c in ascending order

    # Iterate through list c and calculate answer
    for i in range(n):
        ans = (ans + (n + 1 - i) * c[i] % mod) % mod

    # Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
    print(ans * modpow(4, n - 1) % mod)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
