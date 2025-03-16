#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ll long long

# Function to swap two integers
def swap(x, y):
    temp = x
    x = y
    y = temp

    return

# Function to compute the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    c = 0

    # Use the Euclidean algorithm to find GCD
    while b > 0:
        c = a % b
        a = b
        b = c

    return a # Return the GCD

# Comparison function for sorting in ascending order
def upll(a, b):
    return (ll)a < (ll)b and -1 or (ll)a > (ll)b and 1 or 0

# Comparison function for sorting in descending order
def downll(a, b):
    return (ll)a < (ll)b and 1 or (ll)a > (ll)b and -1 or 0

# Function to sort an array in ascending order
def sortup(a, n):
    qsort(a, n, sizeof(ll), upll) # Use qsort with the ascending comparison function

# Function to sort an array in descending order
def sortdown(a, n):
    qsort(a, n, sizeof(ll), downll) # Use qsort with the descending comparison function

# Function to compute modular exponentiation
def modpow(a, n, mod):
    ans = 1

    # Exponentiation by squaring method
    while n > 0:
        if n & 1: # If n is odd
            ans = ans * a % mod # Multiply the base with the result
        a = a * a % mod # Square the base
        n /= 2 # Divide n by 2

    return ans # Return the result

# Function to compute modular inverse using Fermat's little theorem
def modinv(a, mod):
    return modpow(a, mod - 2, mod) # a^(mod-2) mod mod

# Function to return the maximum of two integers
def max(a, b):
    if a < b:
        return b # Return b if a is less than b
    else:
        return a # Otherwise return a

# Function to return the minimum of two integers
def min(a, b):
    if a < b:
        return a # Return a if it is less than b
    else:
        return b # Otherwise return b

# Function to update the value of a if b is greater
def chmax(a, b):
    if a < b:
        a = b # Update a to b if b is greater

    return

# Function to update the value of a if b is smaller
def chmin(a, b):
    if a > b:
        a = b # Update a to b if b is smaller

    return

# Main function
def main():
    n = 0 # Initialize n to 0
    # Read an integer n from input
    scanf("%d", &n)
    sum = 0 # Initialize sum to 0
    m = n # Store the original value of n

    # Calculate the sum of the digits of n (up to 9 digits)
    for i in range(9):
        sum += n % 10 # Add the last digit to sum
        n /= 10 # Remove the last digit

    # Check if m is divisible by the sum of its digits
    if m % sum == 0:
        printf("Yes\n") # Print "Yes" if divisible
    else:
        printf("No\n") # Print "No" if not divisible

    return 0 # Return success

