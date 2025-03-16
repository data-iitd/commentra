import math
from functools import reduce
from collections import deque, Counter
import sys

# Set the maximum recursion limit to handle deep recursions
sys.setrecursionlimit(10 ** 7)

# Function to read a single line of input
def input():
    return sys.stdin.readline().strip()

# Function to read a list of integers from a single line of input
def get_nums_l():
    return [int(s) for s in input().split(" ")]

# Function to read 'n' integers from input, one per line
def get_nums_n(n):
    return [int(input()) for _ in range(n)]

# Function to read all integers from standard input
def get_all_int():
    return map(int, open(0).read().split())

# Generator function to yield elements from an iterable within a specified range
def rangeI(it, l, r):
    for i, e in enumerate(it):
        if l <= i < r:
            yield e
        elif l >= r:
            break

# Debugging function to print debug messages to stderr
def log(*args):
    print("DEBUG:", *args, file=sys.stderr)

# Define a large constant for infinity
INF = 999999999999999999999999

# Define a modulus constant for calculations
MOD = 10 ** 9 + 7

# Read an integer 'n' from input
n = int(input())

# If n is 1, print 0 and exit
if n == 1:
    print(0)
    exit()

# Function to perform prime factorization of a number
def prime_factorize(n):
    a = []
    # Divide n by 2 until it is odd
    while n % 2 == 0:
        a.append(2)
        n //= 2
    
    # Check for odd factors from 3 upwards
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    
    # If n is still greater than 1, it is a prime factor
    if n != 1:
        a.append(n)
    
    return a

# Perform prime factorization on n
fac_ = prime_factorize(n)

# Count the occurrences of each prime factor
fac = Counter(fac_)

# Initialize the answer variable
ans = 0

# Calculate the number of ways to express the prime factors
for p, e in fac.items():
    x = e
    # For each prime factor's exponent, calculate how many times it can be used
    for i in range(1, 99999999):
        if x >= i:
            x -= i
            ans += 1
        else:
            break

# Print the final answer
print(ans)
