
import sys

# Function to swap two integers
def swap(x, y):
    temp = x
    x = y
    y = temp
    return x, y

# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    c = a % b
    while b > 0:
        a = b
        b = c
        c = a % b
    return a

# Function to compare long long integers for ascending order in sorting
def upll(a, b):
    if a < b:
        return -1
    elif a > b:
        return 1
    else:
        return 0

# Function to compare long long integers for descending order in sorting
def downll(a, b):
    if a < b:
        return 1
    elif a > b:
        return -1
    else:
        return 0

# Function to sort an array of long long integers in ascending order
def sortup(a, n):
    a.sort(key=lambda x: x)

# Function to sort an array of long long integers in descending order
def sortdown(a, n):
    a.sort(key=lambda x: -x)

# Function to calculate (a^n) % mod using modular exponentiation
def modpow(a, n, mod):
    ans = 1
    while n > 0:
        if n % 2 == 1:
            ans = (ans * a) % mod
        a = (a * a) % mod
        n //= 2
    return ans

# Function to calculate modular multiplicative inverse
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

# Function to update a variable if it is smaller
def chmax(a, b):
    if a < b:
        a = b
    return a

# Function to update a variable if it is larger
def chmin(a, b):
    if a > b:
        a = b
    return a

# Main function
def main():
    n = int(input())
    sum = 0
    m = n
    for i in range(9):
        sum += n % 10
        n //= 10
    if m % sum == 0:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

