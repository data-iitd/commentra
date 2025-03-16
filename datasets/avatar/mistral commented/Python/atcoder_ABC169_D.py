# Import necessary libraries and set recursion limit
import math
from functools import reduce
from collections import deque, Counter
import sys
sys.setrecursionlimit(10 ** 7)

# Custom input function
def input():
    return sys.stdin.readline().strip()

# Function to get a list of numbers separated by a space
def get_nums_l():
    return [int(s) for s in input().split()]

# Function to get a list of numbers of a given length
def get_nums_n(n):
    return [int(input()) for _ in range(n)]

# Function to get all integers from a file
def get_all_int():
    return map(int, open(0).read().split())

# Define constants
INF = 999999999999999999999999
MOD = 10 ** 9 + 7

# Get the number of test cases
n = int(input())

# Base case for the recursion
if n == 1:
    print(0)
    exit()

# Function to prime factorize a number
def prime_factorize(n):
    """
    This function prime factorizes a given number n.
    """
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

# Function to calculate the factorial of a number
def factorial(n):
    """
    This function calculates the factorial of a given number n.
    """
    if len(arr) == 0:
        arr.append((n, 1))
    return arr

# Initialize variables
fac_ = prime_factorize(n)
fac = Counter(fac_)
ans = 0

# Calculate the answer
for p, e in fac.items():
    """
    For each prime factor p and its exponent e, calculate the sum of all integers i such that i > 1 and i is a multiple of p^e.
    """
    x = e
    for i in range(1, 1000000000):
        if x >= i:
            x -= i
            ans += 1
        else:
            break

# Print the answer
print(ans)
