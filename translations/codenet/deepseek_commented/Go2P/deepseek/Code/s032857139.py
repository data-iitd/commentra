import sys
import math
from io import StringIO

# I/O functions for reading input efficiently.
def input():
    return sys.stdin.readline().strip()

def read_int():
    return int(input())

def read_int_slice(n):
    return list(map(int, input().split()))

def read_float():
    return float(input())

def read_float_slice(n):
    return list(map(float, input().split()))

def read_str():
    return input()

def read_str_slice(n):
    return input().split()

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
    return (num >> nth) & 1

# Arithmetic functions for mathematical operations.
def max_int(integers):
    return max(integers)

def min_int(integers):
    return min(integers)

def ceil_int(a, b):
    return -(-a // b)

def floor_int(a, b):
    return a // b

def pow_int(a, e):
    return a ** e

def abs_int(a):
    return abs(a)

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

# Utility functions for string manipulation and permutation.
def delete_element(s, i):
    return s[:i] + s[i+1:]

def concat(s, t):
    return s + t

def upper_rune(r):
    return r.upper()

def lower_rune(r):
    return r.lower()

def toggle_rune(r):
    return r.swapcase()

def toggle_string(s):
    return s.swapcase()

def strtoi(s):
    return int(s)

# Functions for generating permutations.
def calc_factorial_patterns(elements):
    return factorial_recursion([], elements)

def factorial_recursion(interim, residual):
    if not residual:
        return [interim]
    res = []
    for i, elem in enumerate(residual):
        new_interim = interim + [elem]
        new_residual = residual[:i] + residual[i+1:]
        res.extend(factorial_recursion(new_interim, new_residual))
    return res

def calc_duplicate_patterns(elements, digit):
    return duplicate_recursion([], elements, digit)

def duplicate_recursion(interim, elements, digit):
    if len(interim) == digit:
        return [interim]
    res = []
    for i in range(len(elements)):
        new_interim = interim + [elements[i]]
        res.extend(duplicate_recursion(new_interim, elements, digit))
    return res

# Binary search functions.
def general_lower_bound(s, key):
    is_ok = lambda index, key: s[index] >= key
    ng, ok = -1, len(s)
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if is_ok(mid, key):
            ok = mid
        else:
            ng = mid
    return ok

def general_upper_bound(s, key):
    is_ok = lambda index, key: s[index] > key
    ng, ok = -1, len(s)
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if is_ok(mid, key):
            ok = mid
        else:
            ng = mid
    return ok

# Union-Find data structure.
def init_parents(parents, max_node_id):
    parents[:] = range(max_node_id + 1)

def unite(x, y, parents):
    xp, yp = root(x, parents), root(y, parents)
    if xp == yp:
        return
    parents[xp] = yp

def same(x, y, parents):
    return root(x, parents) == root(y, parents)

def root(x, parents):
    if parents[x] == x:
        return x
    parents[x] = root(parents[x], parents)
    return parents[x]

# Prime factorization and checking.
def trial_division(n):
    if n <= 1:
        raise ValueError("TrialDivision only accepts a NATURAL number")
    p = {}
    for i in range(2, int(math.sqrt(n)) + 1):
        exp = 0
        while n % i == 0:
            exp += 1
            n //= i
        if exp > 0:
            p[i] = exp
    if n > 1:
        p[n] = 1
    return p

def is_prime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Functions for modular arithmetic.
def calc_negative_mod(val, m):
    res = val % m
    if res < 0:
        res += m
    return res

def modpow(a, e, m):
    if e == 0:
        return 1
    if e % 2 == 0:
        half_e = e // 2
        half = modpow(a, half_e, m)
        return half * half % m
    return a * modpow(a, e-1, m) % m

def calc_mod_inv(a, m):
    return modpow(a, m-2, m)

# Min-heap implementation using the heapq module.
import heapq

class IntHeap(list):
    def __init__(self):
        super().__init__()
        heapq.heapify(self)

    def push(self, x):
        heapq.heappush(self, x)

    def pop(self):
        return heapq.heappop(self)

# Main function to read input, sort the array, and calculate the answer.
def main():
    n, x = map(int, input().split())
    A = sorted(read_int_slice(n))
    ans = 0
    for a in A:
        if x >= a:
            ans += 1
            x -= a
        else:
            break
    if ans == n and x > 0:
        ans -= 1
    print(ans)

