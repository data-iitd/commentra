
import sys

# Function to swap two integers
def swap(x, y):
    x, y = y, x
    return x, y

# Function to compute the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    while b!= 0:
        a, b = b, a % b
    return a

# Comparison function for sorting in ascending order
def up(a, b):
    return a < b

# Comparison function for sorting in descending order
def down(a, b):
    return a > b

# Function to sort an array in ascending order
def sortup(a):
    a.sort(key=up)

# Function to sort an array in descending order
def sortdown(a):
    a.sort(key=down)

# Function to compute modular exponentiation
def modpow(a, n, mod):
    ans = 1
    while n > 0:
        if n % 2 == 1:
            ans = (ans * a) % mod
        a = (a * a) % mod
        n //= 2
    return ans

# Function to compute modular inverse using Fermat's little theorem
def modinv(a, mod):
    return modpow(a, mod - 2, mod)

# Function to return the maximum of two integers
def max(a, b):
    if a < b:
        return b
    else:
        return a

# Function to return the minimum of two integers
def min(a, b):
    if a < b:
        return a
    else:
        return b

# Function to update the value of a if b is greater
def chmax(a, b):
    if a < b:
        a = b
    return a

# Function to update the value of a if b is smaller
def chmin(a, b):
    if a > b:
        a = b
    return a

# Main function
def main():
    n = int(input())
    sum = 0
    m = n

    # Calculate the sum of the digits of n (up to 9 digits)
    for i in range(9):
        sum += n % 10
        n //= 10

    # Check if m is divisible by the sum of its digits
    if m % sum == 0:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

