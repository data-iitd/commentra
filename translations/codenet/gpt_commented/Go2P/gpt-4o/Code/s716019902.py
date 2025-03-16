import sys

# Define constants for modulo operation and factorial limit
mod = 998244353
facNum = 300001

def main():
    # Read an integer N from input
    N = int(sys.stdin.readline().strip())
    sum = 0
    
    # Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
    for i in range(1, N + 1):
        if i % 3 == 0 or i % 5 == 0:
            continue  # Skip numbers divisible by 3 or 5
        sum += i  # Add the number to the sum
    
    # Output the final sum
    print(sum)

# Function to calculate a^n under modulo
def Pow(a, n):
    ans = 1
    while n > 0:
        if n & 1 == 1:
            ans = ans * a % mod  # Multiply by a if n is odd
        a = a * a % mod  # Square a
        n >>= 1  # Right shift n
    return ans  # Return the result

# Function to calculate the greatest common divisor of a and b
def Gcd(a, b):
    if a < b:
        return Gcd(b, a)  # Ensure a is greater than b
    while b != 0:
        a, b = b, a % b  # Apply Euclidean algorithm
    return a  # Return the GCD

# Function to return the minimum of two integers
def min(a, b):
    return a if a < b else b  # Return the smaller value

# Function to calculate n choose k using precomputed factorials
def combination(n, k, fac, ifac):
    if n < k or n < 0:
        return 0  # Return 0 if invalid
    if k == 0:
        return 1  # Return 1 if k is 0
    # Calculate combination using factorials
    ans = ifac[k] * ifac[n - k] % mod
    return ans * fac[n] % mod

# Function to precompute factorials and their modular inverses
def factorial():
    fac = [0] * facNum  # Create a list for factorials
    fac[0] = 1
    ifac = [0] * facNum  # Create a list for inverse factorials
    ifac[0] = 1
    for i in range(1, facNum):
        fac[i] = fac[i - 1] * i % mod  # Compute factorial
        ifac[i] = ifac[i - 1] * Pow(i, mod - 2) % mod  # Compute inverse factorial using Fermat's little theorem
    return fac, ifac

# Function to find the index of the first element in a sorted list that is not less than v
def lowerBound(vs, v):
    n = len(vs) // 2  # Initialize mid index
    m = len(vs)  # Length of the list
    while m != n:
        if vs[n] < v:
            n = (m - n + 1) // 2 + n  # Move to the right half
        else:
            m = n  # Move to the left half
            n //= 2  # Update mid index
    return n  # Return the found index

# Function to create a list of integers initialized to a specific value
def IntSlice(n, init):
    return [init] * n  # Create and return the initialized list

if __name__ == "__main__":
    main()

# <END-OF-CODE>
