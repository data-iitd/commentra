

# problem_b.py

import sys
from typing import List

# Define a constant for modulus operation
constMod = 100000007

# Initialize scanner and writer for input and output
sc = sys.stdin.buffer.readline
wr = sys.stdout.buffer.write

# -----------------------------------------

# getInt reads a single integer from input
def getInt() -> int:
    return int(sc().decode().strip())

# getIntSlice reads n integers from input and returns them as a slice
def getIntSlice(n: int) -> List[int]:
    return [getInt() for _ in range(n)]

# getIntDoubleSlice reads m slices of n integers from input and returns them as a 2D slice
def getIntDoubleSlice(m: int, n: int) -> List[List[int]]:
    return [getIntSlice(n) for _ in range(m)]

# getString reads a single string from input
def getString() -> str:
    return sc().decode().strip()

# getStringSlice reads n strings from input and returns them as a slice
def getStringSlice(n: int) -> List[str]:
    return [getString() for _ in range(n)]

# getStringDoubleSlice reads m slices of n strings from input and returns them as a 2D slice
def getStringDoubleSlice(m: int, n: int) -> List[List[str]]:
    return [getStringSlice(n) for _ in range(m)]

# -----------------------------------------

# Sort Functions

# sortIntSlice sorts a slice of integers in ascending order
def sortIntSlice(ns: List[int]) -> List[int]:
    return sorted(ns)

# sortIntReverseSlice sorts a slice of integers in descending order
def sortIntReverseSlice(ns: List[int]) -> List[int]:
    return sorted(ns, reverse=True)

# -----------------------------------------

# Number Functions

# numAbs returns the absolute value of an integer x
def numAbs(x: int) -> int:
    if x < 0:
        return -x
    return x

# numModPow computes a^n % m using modular exponentiation
def numModPow(a: int, n: int, m: int) -> int:
    result = 1

    for _ in range(n):
        if n % 2 == 1:
            result = (result * a) % m
        a = (a * a) % m
        n >>= 1

    return result

# numGcd computes the greatest common divisor of a and b
def numGcd(a: int, b: int) -> int:
    if b == 0:
        return a
    return numGcd(b, a % b)

# numLcm computes the least common multiple of a and b
def numLcm(a: int, b: int) -> int:
    return a * b // numGcd(a, b)

# numModInv computes the modular inverse of a under modulo p
def numModInv(a: int, p: int) -> int:
    if a == 1:
        return 1
    return p - numModInv(p % a, p) * (p // a) % p

# numModFrac computes factorials modulo constMod up to n
def numModFrac(n: int) -> List[int]:
    frac = [1]

    for i in range(1, n + 1):
        frac.append(i * frac[i - 1] % constMod)

    return frac

# numModConb computes nCr % constMod using precomputed factorials
def numModConb(n: int, r: int) -> int:
    frac = numModFrac(n)
    return (frac[n] // ((frac[n - r] * frac[r]) % constMod)) % constMod

# -----------------------------------------

# solve function implements the main logic of the problem
def solve():
    # Read n and m from input
    n, m = getInt(), getInt()
    # Read n integers into slice a
    a = getIntSlice(n)

    # Calculate the sum of all elements in a
    sum = 0
    for v in a:
        sum += v

    # Count how many elements in a meet the required rate
    count = 0
    for v in a:
        rate = sum / (4 * m)
        if v >= rate:
            count += 1

    # Output "Yes" if count is greater than or equal to m, otherwise "No"
    if count >= m:
        wr(b"Yes\n")
    else:
        wr(b"No\n")

# -----------------------------------------

# main function initializes the program and calls solve
def main():
    # Call the solve function to execute the main logic
    solve()
    # Flush the writer to output results
    wr.flush()

# -----------------------------------------

# End of code
