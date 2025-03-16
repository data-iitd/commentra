import sys
import math

from collections import defaultdict
from collections import deque

# Function to load a single value of a specified type from input
def load(vtype=int):
    return vtype(input().strip())

# Function to load a list of values of a specified type from input, separated by a given separator
def load_list(seplator=" ", vtype=int):
    return [vtype(v) for v in input().strip().split(seplator)]

# Function to exit the program
def exit():
    import sys
    sys.exit(0)

# Recursive function to generate all permutations of a list
def perm_sub(li, used):
    # Base case: if the length of used indices equals the length of the list, return an empty deque
    if len(li) == len(used):
        return [deque()]
    
    k = []
    # Iterate through each index in the list
    for i in range(len(li)):
        # Skip if the index is already used
        if i in used:
            continue
        # Mark the index as used
        used.add(i)
        # Recursively generate permutations of the remaining elements
        sub_list = perm_sub(li, used)
        # Prepend the current element to each of the generated permutations
        for sub in sub_list:
            sub.appendleft(li[i])
        # Extend the result list with the new permutations
        k.extend(sub_list)
        # Unmark the index for future permutations
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

# Function to convert a list of digits into a single integer
def li2n(li):
    n, base = 0, 1
    for i in range(len(li)-1, -1, -1):
        n += li[i] * base
        base *= 10
    return n

# Function to convert a list of strings to a list of integers
def sli2ili(li):
    return [int(s) for s in li] 

# Function to generate a list of prime numbers up to n using the Sieve of Eratosthenes
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

# Function to compute the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    a, b = max(a, b), min(a, b)
    while True:
        r = a % b
        if r == 0: return b
        a, b = b, r

# Function to compute the least common multiple (LCM) of two numbers
def lcm(a, b):
    return int(a * b / gcd(a,b))

# Function to generate all subsets of a list
def all_subset(li):
    s = []
    n = len(li)
    # Iterate through all possible combinations using bit manipulation
    for bit in range(0, (1<<(n+1))):
        ss = set()
        for i in range(0, n):
            if (bit & (1 << i)):
                ss.add(li[i])
        s.append(ss)
    return s

# Recursive function to compute the factorial of a number
def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n-1)

# Function to compute combinations (m choose n)
def mCn(m, n):
    # Helper function to compute factorial in a loop
    def factorial_ntimes(m, n):
        r = 1
        while n:
            r *= m
            m -= 1
            n -= 1
        return r
    return int(factorial_ntimes(m, n) / factorial(n))

# Main execution starts here
n = load()  # Load the number of elements
A = load_list()  # Load the list of elements

# Check if all elements in the list are unique
if n == len(set(A)):
    print('YES')  # Print 'YES' if all elements are unique
else:
    print('NO')  # Print 'NO' if there are duplicates
