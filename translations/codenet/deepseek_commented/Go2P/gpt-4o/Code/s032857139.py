import sys
import math
from heapq import heappush, heappop

# Utility functions for reading input efficiently.
def read_int():
    return int(sys.stdin.readline().strip())

def read_int_slice(n):
    return list(map(int, sys.stdin.readline().strip().split()))

# Utility functions for mathematical operations.
def max_value(*integers):
    return max(integers)

def min_value(*integers):
    return min(integers)

def ceil_int(a, b):
    return -(-a // b)

def floor_int(a, b):
    return a // b

def pow_int(a, e):
    if a < 0 or e < 0:
        raise ValueError("[argument error]: pow_int does not accept negative integers")
    return a ** e

def abs_int(a):
    return abs(a)

def gcd(a, b):
    if a <= 0 or b <= 0:
        raise ValueError("[argument error]: gcd only accepts two NATURAL numbers")
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    if a <= 0 or b <= 0:
        raise ValueError("[argument error]: lcm only accepts two NATURAL numbers")
    return (a // gcd(a, b)) * b

# Main function to read input, sort the array, and calculate the answer.
def main():
    n = read_int()
    x = read_int()
    A = read_int_slice(n)

    A.sort()

    ans = 0
    for value in A:
        if x >= value:
            ans += 1
            x -= value
        else:
            break
    if ans == n and x > 0:
        ans -= 1
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
