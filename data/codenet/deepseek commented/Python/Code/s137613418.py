
import sys
import math

from collections import defaultdict
from collections import deque

# Function to load a single value of a specified type
def load(vtype=int):
    return vtype(input().strip())

# Function to load a list of values separated by a specified separator and of a specified type
def load_list(seplator=" ", vtype=int):
    return [vtype(v) for v in input().strip().split(seplator)]

# Function to exit the program
def exit():
    import sys
    sys.exit(0)

# Function to generate all permutations of a list with a set of used indices
def perm_sub(li, used):
    if len(li) == len(used):
        return [deque()]
    k = []
    for i in range(len(li)):
        if i in used:
            continue
        used.add(i)
        sub_list = perm_sub(li, used)
        for sub in sub_list:
            sub.appendleft(li[i])
        k.extend(sub_list)
        used.discard(i)
    return k

# Function to generate all permutations of a list
def perm_li(li):
    return perm_sub(li, set())

# Function to generate all permutations of numbers from 0 to n-1
def perm_n(n):
    return perm_sub(list(range(n)), set())

# Function to join a list of integers into a string with a specified separator
def join_i(li, sep=""):
    return sep.join([str(e) for e in li])

# Function to convert a list of digits into an integer
def li2n(li):
    n, base = 0, 1
    for i in range(len(li)-1, -1, -1):
        n += li[i] * base
        base *= 10
    return n

# Function to convert a list of string digits into a list of integers
def sli2ili(li):
    return [int(s) for s in li] 

# Function to generate a list of prime numbers up to n
def prime_list(n):
    li = [i for i in range(2, n+1)]
    for i in range(len(li)):
        if li[i] >= int(math.sqrt(n)):
            break
        if li[i] == -1:
            continue
        for j in range(i+1, len(li)):
            if li[j] % li[i] == 0:
                li[j] = -1
    return [n for n in li if n != -1]

# Function to calculate the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    a, b = max(a, b), min(a, b)
    while True:
        r = a % b
        if r == 0: return b
        a, b = b, r

# Function to calculate the least common multiple (LCM) of two numbers
def lcm(a, b):
    return int(a * b / gcd(a,b))

# Function to generate all subsets of a list
def all_subset(li):
    s = []
    n = len(li)
    for bit in range(0, (1<<(n+1))):
        ss = set()
        for i in range(0, n):
            if (bit & (1 << i)):
                ss.add(li[i])
        s.append(ss)
    return s

# Function to calculate the factorial of a number
def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n-1)

# Function to calculate the binomial coefficient "m choose n"
def mCn(m, n):
    def factorial_ntimes(m, n):
        r = 1
        while n:
            r *= m
            m -= 1
            n -= 1
        return r
    return int(factorial_ntimes(m, n) / factorial(n))

# Main program logic
n = load()
A = load_list()

# Check if the number of unique elements in A is equal to n
if n == len(set(A)):
    print('YES')
else:
    print('NO')