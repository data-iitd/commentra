

import sys

def modinv(a, m): # Function to calculate the modular inverse of 'a' with respect to'm'
    b = m
    u = 1
    v = 0
    while b > 0:
        t = a // b
        a -= t * b
        u -= t * v
        b, a = a, b
    u %= m # If the result is negative, add'm' to make it positive
    if u < 0:
        u += m
    return u # Return the modular inverse

def main():
    n = int(input()) # Read the number of elements in the array
    a = list(map(int, input().split())) # Read the array elements and convert them to integers
    mod = 1000000007 # Set the modulus value
    p = 1 # Initialize 'p' variable to calculate the factorial of all numbers from 2 to 'n'

    # Calculate the factorial of all numbers from 2 to 'n' and store it in 'p' variable
    for i in range(2, n + 1):
        p = (p * i) % mod

    q = [1] * n # Initialize a list 'q' of size 'n' with all elements as 1
    for i in range(1, n):
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod

    ans = 0 # Initialize the answer variable

    # Calculate the answer using the formula ans = sum of (q[i] * a[i] * p) for all i from 0 to n-1
    for i in range(n):
        val = (q[i] + q[n - i - 1] - 1) % mod # Calculate the value of 'val' using the formula
        val = (val * a[i]) % mod # Multiply 'val' with 'a[i]'
        val = (val * p) % mod # Multiply 'val' with 'p'
        ans = (ans + val) % mod # Add the result to the answer

    print(ans) # Print the answer

if __name__ == "__main__":
    main() # Call the main function

