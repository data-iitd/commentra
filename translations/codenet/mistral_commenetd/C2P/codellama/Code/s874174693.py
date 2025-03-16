
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

# Function to find the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    c = a % b
    while b > 0:
        a = b
        b = c
        c = a % b
    return a

# Comparator function for qsort() to sort in ascending order
def upll(a, b):
    if a < b:
        return -1
    elif a > b:
        return 1
    else:
        return 0

# Comparator function for qsort() to sort in descending order
def downll(a, b):
    if a < b:
        return 1
    elif a > b:
        return -1
    else:
        return 0

# Function to sort an array in ascending order using qsort()
def sortup(a, n):
    qsort(a, n, sizeof(ll), upll)

# Function to sort an array in descending order using qsort()
def sortdown(a, n):
    qsort(a, n, sizeof(ll), downll)

# Function to calculate a^n modulo m
def modpow(a, n, mod):
    ans = 1
    while n > 0:
        if n & 1:
            ans = ans * a % mod
        a = a * a % mod
        n /= 2
    return ans

# Function to find the modular multiplicative inverse of a modulo m
def modinv(a, mod):
    return modpow(a, mod - 2, mod)

# Function to find the maximum of two integers
def max(a, b):
    if a < b:
        return b
    else:
        return a

# Function to find the minimum of two integers
def min(a, b):
    if a < b:
        return a
    else:
        return b

# Function to update the value of a variable with the maximum of the current value and a new value
def chmax(a, b):
    if a < b:
        a = b

# Function to update the value of a variable with the minimum of the current value and a new value
def chmin(a, b):
    if a > b:
        a = b

# Main function
def main():
    n = 0 # Variable to store the number of digits in the given number
    sum = 0 # Variable to store the sum of digits
    m = 0 # Variable to store the given number

    # Read the number of digits from the standard input
    scanf("%d", &n)

    # Initialize m with the given number
    m = n

    # Calculate the sum of digits
    for i in range(9):
        sum += m % 10
        m /= 10

    # Check if the given number is divisible by the sum of its digits
    if m % sum == 0:
        printf("Yes\n") # If yes, print "Yes"
    else:
        printf("No\n") # If no, print "No"

    return 0 # Return 0 to indicate successful execution

# The above code now includes comments for each logical block. These comments should help in understanding the code better.

