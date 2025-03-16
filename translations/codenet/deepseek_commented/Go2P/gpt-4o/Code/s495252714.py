import sys
from functools import reduce

# Define the constant for modular arithmetic.
mod = 1000000007

# Function to perform modular exponentiation.
def modpow(a, n):
    res = 1
    while n > 0:
        if n & 1 == 1:
            res = res * a % mod
        a = a * a % mod
        n >>= 1
    return res

# Main function of the program.
def main():
    # Read the number of elements.
    n = int(sys.stdin.readline().strip())
    
    # Read n integers into a list.
    c = list(map(int, sys.stdin.readline().strip().split()))
    
    # Initialize the answer variable.
    ans = 0
    
    # Sort the list of integers.
    c.sort()
    
    # Calculate the answer based on the sorted list.
    for i in range(n):
        ans = (ans + (n + 1 - i) * c[i] % mod) % mod
    
    # Print the final answer, multiplied by 4^(n-1) modulo mod.
    print(ans * modpow(4, n - 1) % mod)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
