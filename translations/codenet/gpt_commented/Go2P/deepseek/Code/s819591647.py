# problem_b.py

import sys
import math

# Define a constant for modulus operation
constMod = int(1e9) + 7

# Initialize reader and writer for input and output
reader = sys.stdin
writer = sys.stdout

# -----------------------------------------

# getInt reads a single integer from input
def getInt():
    return int(reader.readline().strip())

# getIntSlice reads n integers from input and returns them as a list
def getIntSlice(n):
    return list(map(int, reader.readline().strip().split()))

# getIntDoubleSlice reads m slices of n integers from input and returns them as a 2D list
def getIntDoubleSlice(m, n):
    return [getIntSlice(n) for _ in range(m)]

# getString reads a single string from input
def getString():
    return reader.readline().strip()

# getStringSlice reads n strings from input and returns them as a list
def getStringSlice(n):
    return [getString() for _ in range(n)]

# getStringDoubleSlice reads m slices of n strings from input and returns them as a 2D list
def getStringDoubleSlice(m, n):
    return [getStringSlice(n) for _ in range(m)]

# -----------------------------------------

# Sort Functions

# sortIntSlice sorts a list of integers in ascending order
def sortIntSlice(ns):
    return sorted(ns)

# sortIntReverseSlice sorts a list of integers in descending order
def sortIntReverseSlice(ns):
    return sorted(ns, reverse=True)

# -----------------------------------------

# Number Functions

# numAbs returns the absolute value of an integer x
def numAbs(x):
    return abs(x)

# numModPow computes a^n % m using modular exponentiation
def numModPow(a, n, m):
    result = 1
    while n > 0:
        if n % 2 == 1:
            result = (result * a) % m
        a = (a * a) % m
        n >>= 1
    return result

# numGcd computes the greatest common divisor of a and b
def numGcd(a, b):
    while b:
        a, b = b, a % b
    return a

# numLcm computes the least common multiple of a and b
def numLcm(a, b):
    return a * b // numGcd(a, b)

# numModInv computes the modular inverse of a under modulo p
def numModInv(a, p):
    if a == 1:
        return 1
    return p - numModInv(p % a, p) * (p // a) % p

# numModFrac computes factorials modulo constMod up to n
def numModFrac(n):
    frac = [1]
    for i in range(1, n + 1):
        frac.append(i * frac[i - 1] % constMod)
    return frac

# numModConb computes nCr % constMod using precomputed factorials
def numModConb(n, r):
    frac = numModFrac(n)
    return (frac[n] // ((frac[n - r] * frac[r]) % constMod)) % constMod

# -----------------------------------------

# solve function implements the main logic of the problem
def solve():
    # Read n and m from input
    n, m = map(int, reader.readline().strip().split())
    # Read n integers into list a
    a = getIntSlice(n)

    # Calculate the sum of all elements in a
    sum_a = sum(a)

    # Count how many elements in a meet the required rate
    count = sum(1 for v in a if v >= sum_a / (4 * m))

    # Output "Yes" if count is greater than or equal to m, otherwise "No"
    writer.write("Yes\n" if count >= m else "No\n")

# -----------------------------------------

# main function initializes the program and calls solve
if __name__ == "__main__":
    # Call the solve function to execute the main logic
    solve()
    # Flush the writer to output results
    writer.flush()
