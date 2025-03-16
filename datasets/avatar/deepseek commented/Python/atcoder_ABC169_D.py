import math
from functools import reduce
from collections import deque, Counter
import sys
sys.setrecursionlimit(10 ** 7)  # Set recursion limit for the program

def input():
    return sys.stdin.readline().strip()  # Function to read a single line of input

def get_nums_l():
    return [int(s) for s in input().split(" ")]  # Parse space-separated numbers

def get_nums_n(n):
    return [int(input()) for _ in range(n)]  # Read n integers from input

def get_all_int():
    return map(int, open(0).read().split())  # Read all integers from input

def rangeI(it, l, r):
    for i, e in enumerate(it):
        if l <= i < r:
            yield e
        elif l >= r:
            break

def log(*args):
    print("DEBUG:", *args, file=sys.stderr)  # Debugging function to print statements

INF = 999999999999999999999999  # Constant for infinity
MOD = 10 ** 9 + 7  # Constant for a large prime number

n = int(input())  # Read the integer n
if n == 1:
    print(0)  # If n is 1, print 0 and exit
    exit()

def prime_factorize(n):
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

fac_ = prime_factorize(n)  # Get the prime factorization of n
fac = Counter(fac_)  # Count the occurrences of each prime factor
ans = 0
for p, e in fac.items():
    x = e
    for i in range(1, 99999999):
        if x >= i:
            x -= i
            ans += 1
        else:
            break

print(ans)  # Print the final answer
