# Import necessary modules and define helper functions
import sys
import math

from collections import defaultdict, deque

def load(vtype=int):
    """
    Loads a value from the standard input and converts it to the specified type.
    """
    return vtype(input().strip())

def load_list(seplator=" ", vtype=int):
    """
    Loads a list of values from the standard input, with each value separated by the specified separator, and converts each value to the specified type.
    """
    return [vtype(v) for v in input().strip().split(seplator)]

def exit():
    """
    Exits the program with a status code of 0.
    """
    import sys
    sys.exit(0)

# Generate permutations
def perm_sub(li, used):
    """
    Generates all permutations of the list `li` that do not include any element that is already in the list `used`.
    """
    if len(li) == len(used):
        return [deque()]

    result = []
    for i in range(len(li)):
        if i in used:
            continue
        used.add(i)
        sub_perms = perm_sub(li, used)
        for sub_perm in sub_perms:
            result.append(deque(sub_perm + [li[i]]))
            used.discard(i)
        used.discard(i)

    return result

def perm_li(li):
    """
    Generates all permutations of the list `li`.
    """
    return perm_sub(li, set())

def perm_n(n):
    """
    Generates all permutations of the numbers 0 through `n-1`.
    """
    return perm_sub(list(range(n)), set())

def join_i(li, sep=""):
    """
    Joins a list of integers with the specified separator and returns the result as a string.
    """
    return sep.join([str(e) for e in li])

# Convert a list to a number
def li2n(li):
    """
    Converts a list of integers to a single integer by concatenating the digits in reverse order.
    """
    n, base = 0, 1
    for i in range(len(li)-1, -1, -1):
        n += li[i] * base
        base *= 10
    return n

# Convert a list of strings to a list of integers
def sli2ili(li):
    """
    Converts a list of strings to a list of integers.
    """
    return [int(s) for s in li]

# Generate prime numbers
def prime_list(n):
    """
    Generates a list of prime numbers up to `n`.
    """
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

# Find the greatest common divisor and least common multiple
def gcd(a, b):
    """
    Finds the greatest common divisor of `a` and `b`.
    """
    a, b = max(a, b), min(a, b)
    while True:
        r = a % b
        if r == 0: return b
        a, b = b, r

def lcm(a, b):
    """
    Finds the least common multiple of `a` and `b`.
    """
    return int(a * b / gcd(a, b))

# Generate all subsets of a list
def all_subset(li):
    """
    Generates all subsets of the list `li`.
    """
    s = []
    for bit in range(0, (1<<(len(li)+1))):
        ss = set()
        for i in range(len(li)):
            if (bit & (1 << i)):
                ss.add(li[i])
        s.append(ss)
    return s

# Calculate the factorial of a number
def factorial(n):
    """
    Calculates the factorial of the number `n`.
    """
    if n == 1:
        return 1
    return n * factorial(n-1)

# Calculate the number of combinations of `m` items taken `n` at a time
def mCn(m, n):
    """
    Calculates the number of combinations of `m` items taken `n` at a time.
    """
    return int(factorial(m) / (factorial(n) * factorial(m-n)))

# Load the number of elements and the list of elements from the standard input
n = load()
A = load_list()

# Check if all elements in the list `A` are unique
if len(set(A)) == len(A):
    print('YES')
else:
    print('NO')
