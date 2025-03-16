
# Define constants for modulo operation and factorial limit
mod = 998244353
facNum = 300001

def main():
    # Initialize a new scanner for reading input
    sc = Scanner(sys.stdin)
    # Read an integer N from input
    N = sc.i()
    sum = 0
    
    # Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
    for i in range(1, N+1):
        if i % 3 == 0 or i % 5 == 0:
            continue # Skip numbers divisible by 3 or 5
        sum += i # Add the number to the sum
    
    # Output the final sum
    print(sum)

# Scanner class for handling input
class Scanner:
    def __init__(self, input):
        self.sc = input.split()
        self.i = 0
    
    # s reads a string from the scanner
    def s(self):
        self.i += 1
        return self.sc[self.i-1]
    
    # i reads an integer from the scanner
    def i(self):
        return int(self.s())
    
    # f reads a float64 from the scanner
    def f(self):
        return float(self.s())
    
    # bs reads a byte slice from the scanner
    def bs(self):
        return bytearray(self.s())
    
    # is reads n integers from the scanner into a slice
    def is(self, n):
        return [self.i() for _ in range(n)]
    
    # fs reads n float64 values from the scanner into a slice
    def fs(self, n):
        return [self.f() for _ in range(n)]

# Pow calculates a^n under modulo
def Pow(a, n):
    ans = 1
    for _ in range(n):
        if (n & 1) == 1:
            ans = ans * a % mod # Multiply by a if n is odd
        a = a * a % mod # Square a
        n = n >> 1 # Right shift n
    return ans # Return the result

# Gcd calculates the greatest common divisor of a and b
def Gcd(a, b):
    if a < b:
        return Gcd(b, a) # Ensure a is greater than b
    while b != 0:
        a, b = b, a%b # Apply Euclidean algorithm
    return a # Return the GCD

# min returns the minimum of two integers
def min(a, b):
    if a < b:
        return a # Return a if it's smaller
    return b # Otherwise return b

# combination calculates n choose k using precomputed factorials
def combination(n, k, fac, ifac):
    if n < k or n < 0:
        return 0 # Return 0 if invalid
    if k == 0:
        return 1 # Return 1 if k is 0
    # Calculate combination using factorials
    ans = ifac[k] * ifac[n-k] % mod
    return ans * fac[n] % mod

# factorial precomputes factorials and their modular inverses
def factorial():
    fac = [1] * facNum # Create a slice for factorials
    ifac = [1] * facNum # Create a slice for inverse factorials
    for i in range(1, facNum):
        fac[i] = fac[i-1] * i % mod # Compute factorial
        ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod # Compute inverse factorial using Fermat's little theorem
    return fac, ifac

# lowerBound finds the index of the first element in a sorted slice that is not less than v
def lowerBound(vs, v):
    n = len(vs) // 2 # Initialize mid index
    m = len(vs) # Length of the slice
    while m != n:
        if vs[n] < v:
            n = (m-n+1)//2 + n # Move to the right half
        else:
            m = n # Move to the left half
            n = n // 2 # Update mid index
    return n # Return the found index

# IntSlice creates a slice of integers initialized to a specific value
def IntSlice(n, init):
    r = [init] * n # Create a slice of length n
    return r # Return the initialized slice

