import sys
import math

#=====I/O=====

# Declare reader and writer for input and output
input = sys.stdin.readline
print = sys.stdout.write

# Function to scan an integer from input
def scan_int():
    return int(input().strip())

# Function to scan multiple integers from input
def scan_ints(n):
    return list(map(int, input().strip().split()))

# Function to print integers to output
def print_ints(a, end="\n"):
    print(" ".join(map(str, a)) + end)

#=====main=====

# Main function where execution starts
def main():
    n = scan_int() # Read the number of integers
    c = scan_ints(n) # Read n integers into list c
    c.sort() # Sort the list of integers

    ans = 0 # Initialize answer variable
    mod = 1000000007 # Define a constant for the modulus

    # Calculate the answer based on the sorted integers
    for i in range(n):
        ans = (ans + (n+1-i) * c[i] % mod) % mod # Update the answer using the formula

    # Print the final result after applying modular exponentiation
    print(str((ans * pow(4, n-1, mod)) % mod) + "\n")

# Function to perform modular exponentiation
def pow(a, n, mod):
    res = 1 # Initialize result
    while n > 0:
        if n % 2 == 1: # If n is odd
            res = res * a % mod # Update result
        a = a * a % mod # Square the base
        n = n // 2 # Divide n by 2
    return res # Return the final result

# Call the main function
main()
