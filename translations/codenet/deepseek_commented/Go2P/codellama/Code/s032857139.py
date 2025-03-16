
# Package main defines the entry point of the application.
import sys
import math
import heapq
import bisect
import itertools



# I/O functions for reading input efficiently.
def read_line():
    return sys.stdin.readline().rstrip()

def read_int():
    return int(read_line())

def read_int_array():
    return list(map(int, read_line().split()))

def read_string():
    return read_line()

def read_string_array():
    return read_line().split()



# Utility functions for dynamic programming.
def chmin(updated_value, target):
    if updated_value > target:
        updated_value = target
        return True
    return False

def chmax(updated_value, target):
    if updated_value < target:
        updated_value = target
        return True
    return False

def get_nth_bit(num, nth):
    return num >> nth & 1



# Arithmetic functions for mathematical operations.
def max(integers):
    return max(integers)

def min(integers):
    return min(integers)

def ceil_int(a, b):
    return int(math.ceil(a / b))

def floor_int(a, b):
    return int(math.floor(a / b))

def pow_int(a, e):
    if a < 0 or e < 0:
        raise ValueError("[argument error]: PowInt does not accept negative integers")
    if e == 0:
        return 1
    if e%2 == 0:
        half_e = e // 2
        half = pow_int(a, half_e)
        return half * half
    else:
        return a * pow_int(a, e-1)

def abs_int(a):
    if a < 0:
        return -a
    else:
        return a

def gcd(a, b):
    if a <= 0 or b <= 0:
        raise ValueError("[argument error]: Gcd only accepts two NATURAL numbers")
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    if a <= 0 or b <= 0:
        raise ValueError("[argument error]: Gcd only accepts two NATURAL numbers")
    return (a / gcd(a, b)) * b



# Utility functions for string manipulation and permutation.
def delete_element(s, i):
    if i < 0 or len(s) <= i:
        raise IndexError("[index error]")
    return s[:i] + s[i+1:]

def concat(s, t):
    return s + t

def upper_string(s):
    return s.upper()

def lower_string(s):
    return s.lower()

def toggle_string(s):
    return s.swapcase()

def strtoi(s):
    try:
        return int(s)
    except ValueError:
        raise ValueError("[argument error]: strtoi only accepts integer string")



# Functions for generating permutations.
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

def permutation(n, k):
    if n < k:
        raise ValueError("[argument error]: n should be larger than k")
    if n == k:
        return 1
    else:
        return factorial(n) // factorial(n-k)

def combination(n, k):
    if n < k:
        raise ValueError("[argument error]: n should be larger than k")
    if n == k:
        return 1
    else:
        return permutation(n, k) // factorial(k)

def permutation_with_repetition(n, k):
    return permutation(n+k-1, k)

def combination_with_repetition(n, k):
    return combination(n+k-1, k)

def permutations(iterable, r=None):
    pool = tuple(iterable)
    n = len(pool)
    r = n if r is None else r
    if r > n:
        return
    indices = list(range(n))
    cycles = list(range(n, n-r, -1))
    yield tuple(pool[i] for i in indices[:r])
    while n:
        for i in reversed(range(r)):
            cycles[i] -= 1
            if cycles[i] == 0:
                indices[i:] = indices[i+1:] + indices[i:i+1]
                cycles[i] = n - i
            else:
                j = cycles[i]
                indices[i], indices[-j] = indices[-j], indices[i]
                yield tuple(pool[i] for i in indices[:r])
                break
        else:
            return

def combinations(iterable, r):
    pool = tuple(iterable)
    n = len(pool)
    if r > n:
        return
    indices = list(range(n))
    cycles = list(range(n, n-r+1, -1))
    yield tuple(pool[i] for i in indices[:r])
    while n:
        for i in reversed(range(r)):
            cycles[i] -= 1
            if cycles[i] == 0:
                indices[i:] = indices[i+1:] + indices[i:i+1]
                cycles[i] = n - i
            else:
                j = cycles[i]
                indices[i], indices[-j] = indices[-j], indices[i]
                yield tuple(pool[i] for i in indices[:r])
                break
        else:
            return



# Functions for generating combinations.
def combinations_with_repetition(iterable, r):
    pool = tuple(iterable)
    n = len(pool)
    if r > n:
        return
    indices = [0] * r
    yield tuple(pool[i] for i in indices)
    while True:
        for i in reversed(range(r)):
            if indices[i] != n:
                break
        else:
            return
        indices[i:] = [indices[i] + 1] * (r - i)
        for j in range(i+1, r):
            indices[j] = indices[j-1] + 1
        yield tuple(pool[i] for i in indices)



# Functions for binary search.
def lower_bound(arr, target):
    if len(arr) == 0:
        return 0
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] >= target:
            high = mid - 1
        else:
            low = mid + 1
    return low

def upper_bound(arr, target):
    if len(arr) == 0:
        return 0
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] > target:
            high = mid - 1
        else:
            low = mid + 1
    return low



# Union-Find data structure.
def init_parents(n):
    return list(range(n))

def find_root(x, parents):
    if parents[x] == x:
        return x
    else:
        parents[x] = find_root(parents[x], parents)
        return parents[x]

def unite(x, y, parents):
    x = find_root(x, parents)
    y = find_root(y, parents)
    if x == y:
        return
    parents[x] = y

def same(x, y, parents):
    return find_root(x, parents) == find_root(y, parents)



# Prime factorization and checking.
def trial_division(n):
    if n <= 1:
        raise ValueError("[argument error]: TrialDivision only accepts a NATURAL number")

    p = {}
    for i in range(2, int(n**0.5)+1):
        exp = 0
        while n % i == 0:
            exp += 1
            n //= i
        if exp == 0:
            continue
        p[i] = exp
    if n > 1:
        p[n] = 1
    return p

def is_prime(n):
    if n == 1:
        return False

    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True



# Min-heap implementation using the heapq package.
def init_min_heap(arr):
    return list(arr)

def push_min_heap(heap, x):
    heapq.heappush(heap, x)

def pop_min_heap(heap):
    return heapq.heappop(heap)



# Main function to read input, sort the array, and calculate the answer.
n, x = map(int, input().split())
A = list(map(int, input().split()))

A.sort()

ans = 0
for i in range(n):
    if x >= A[i]:
        ans += 1
        x -= A[i]
    else:
        break
if ans == n and x > 0:
    ans -= 1
print(ans)

