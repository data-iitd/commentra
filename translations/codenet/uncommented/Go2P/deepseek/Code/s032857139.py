import sys
import math
from io import StringIO
import os
import heapq
import string
from bisect import bisect_left, bisect_right
from collections import deque, defaultdict, Counter
from itertools import permutations, combinations, product
from functools import lru_cache
from decimal import Decimal

# Mock input function for testing
def mock_input(input_str):
    """Mock the input function for testing."""
    def input_generator():
        for line in input_str.splitlines():
            yield line
    gen = input_generator()
    return lambda: next(gen)

# Mock input for testing
input_str = """5 10
1 2 3 4 5"""
sys.stdin = StringIO(input_str)

# ReadString returns a WORD string.
def read_string():
    return sys.stdin.readline().strip()

# ReadInt returns an integer.
def read_int():
    return int(read_string())

# ReadIntSlice returns an integer slice that has n integers.
def read_int_slice(n):
    return list(map(int, read_string().split()))

# ReadRuneSlice returns a rune slice.
def read_rune_slice():
    return list(read_string())

# ChMin accepts a pointer of integer and a target value.
# If target value is SMALLER than the first argument,
# then the first argument will be updated by the second argument.
def ch_min(updated_value, target):
    if updated_value > target:
        updated_value = target
        return True
    return False

# ChMax accepts a pointer of integer and a target value.
# If target value is LARGER than the first argument,
# then the first argument will be updated by the second argument.
def ch_max(updated_value, target):
    if updated_value < target:
        updated_value = target
        return True
    return False

# GetNthBit returns nth bit value of an argument.
# n starts from 0.
def get_nth_bit(num, nth):
    return (num >> nth) & 1

# Max returns the max integer among input set.
# This function needs at least 1 argument (no argument causes panic).
def max_int(*integers):
    m = integers[0]
    for integer in integers:
        if m < integer:
            m = integer
    return m

# Min returns the min integer among input set.
# This function needs at least 1 argument (no argument causes panic).
def min_int(*integers):
    m = integers[0]
    for integer in integers:
        if m > integer:
            m = integer
    return m

# CeilInt returns the minimum integer larger than or equal to float(a/b).
def ceil_int(a, b):
    res = a // b
    if a % b > 0:
        res += 1
    return res

# FloorInt returns the maximum integer smaller than or equal to float(a/b)
def floor_int(a, b):
    res = a // b
    return res

# PowInt is integer version of math.Pow
# PowInt calculate a power by Binary Power (二分累乗法(O(log e))).
def pow_int(a, e):
    if a < 0 or e < 0:
        raise ValueError("PowInt does not accept negative integers")

    if e == 0:
        return 1

    if e % 2 == 0:
        half_e = e // 2
        half = pow_int(a, half_e)
        return half * half

    return a * pow_int(a, e-1)

# AbsInt is integer version of math.Abs
def abs_int(a):
    if a < 0:
        return -a
    return a

# Gcd returns the Greatest Common Divisor of two natural numbers.
# Gcd only accepts two natural numbers (a, b >= 1).
# 0 or negative number causes panic.
# Gcd uses the Euclidean Algorithm.
def gcd(a, b):
    if a <= 0 or b <= 0:
        raise ValueError("Gcd only accepts two NATURAL numbers")
    if a < b:
        a, b = b, a

    # Euclidean Algorithm
    while b > 0:
        div = a % b
        a, b = b, div

    return a

# Lcm returns the Least Common Multiple of two natural numbers.
# Lcd only accepts two natural numbers (a, b >= 1).
# 0 or negative number causes panic.
# Lcd uses the Euclidean Algorithm indirectly.
def lcm(a, b):
    if a <= 0 or b <= 0:
        raise ValueError("Gcd only accepts two NATURAL numbers")

    # a = a'*gcd, b = b'*gcd, a*b = a'*b'*gcd^2
    # a' and b' are relatively prime numbers
    # gcd consists of prime numbers, that are included in a and b
    gcd_val = gcd(a, b)

    # not (a * b / gcd), because of reducing a probability of overflow
    return (a // gcd_val) * b

# DeleteElement returns a *NEW* slice, that have the same and minimum length and capacity.
# DeleteElement makes a new slice by using easy slice literal.
def delete_element(s, i):
    if i < 0 or len(s) <= i:
        raise ValueError("Index error")
    return s[:i] + s[i+1:]

# Concat returns a *NEW* slice, that have the same and minimum length and capacity.
def concat(s, t):
    return s + t

# UpperRune is rune version of `strings.ToUpper()`.
def upper_rune(r):
    return ord(str.upper(chr(r)))

# LowerRune is rune version of `strings.ToLower()`.
def lower_rune(r):
    return ord(str.lower(chr(r)))

# ToggleRune returns a upper case if an input is a lower case, v.v.
def toggle_rune(r):
    if 'a' <= chr(r) <= 'z':
        return upper_rune(r)
    elif 'A' <= chr(r) <= 'Z':
        return lower_rune(r)
    else:
        return r

# ToggleString iteratively calls ToggleRune, and returns the toggled string.
def toggle_string(s):
    return ''.join(chr(toggle_rune(ord(c))) for c in s)

# Strtoi is a wrapper of `strconv.Atoi()`.
# If `strconv.Atoi()` returns an error, Strtoi calls panic.
def strtoi(s):
    try:
        return int(s)
    except ValueError:
        panic("Strtoi only accepts integer string")

# CalcNegativeMod can calculate a right residual whether value is positive or negative.
def calc_negative_mod(val, m):
    res = val % m
    if res < 0:
        res += m
    return res

# CalcModInv returns $a^{-1} mod m$ by Fermat's little theorem.
# O(1), but C is nearly equal to 30 (when m is 1000000000+7).
def calc_mod_inv(a, m):
    return pow(a, m-2, m)

# IntHeap is a min-heap of ints.
class IntHeap(list):
    def heappush(self, item):
        heapq.heappush(self, item)

    def heappop(self):
        return heapq.heappop(self)

    def __init__(self, initial=None):
        if initial:
            heapq.heapify(initial)
        else:
            super().__init__()

# Usage:
# h = IntHeap([3, 6, 1, 2])
# heapq.heapify(h)
# heapq.heappush(h, 4)
# popped = heapq.heappop(h)

# Example(ABC111::C)
# odd_count_list, even_count_list = [0] * (10**5+1), [0] * (10**5+1)
# for i in range(10**5+1):
#     odd_count_list[i] = odd_memo[i]
#     even_count_list[i] = even_memo[i]
# odd_count_list.sort(reverse=True)
# even_count_list.sort(reverse=True)

# Example(ABC111::C)
# tmp = calc_factorial_patterns([ord('a'), ord('b'), ord('c')])
# expected = ["abc", "acb", "bac", "bca", "cab", "cba"]
# tmp = calc_duplicate_patterns([ord('a'), ord('b'), ord('c')], 3)
# expected = ["aaa", "aab", "aac", "aba", "abb", "abc", ...]

# GeneralLowerBound returns the smallest index i, that satisfies s[i] >= key.
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

# GeneralUpperBound returns the smallest index i, that satisfies s[i] > key.
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

# Usage:
# test = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 10, 10, 10, 20, 20, 20, 30, 30, 30]
# assert general_upper_bound(test, 5) - general_lower_bound(test, 5) == 5
# assert general_upper_bound(test, 15) - general_lower_bound(test, 15) == 0

# InitParents initializes the parent array for Union-Find.
def init_parents(parents, max_node_id):
    for i in range(max_node_id+1):
        parents[i] = i

# Unite unites two nodes in Union-Find.
def unite(x, y, parents):
    xp, yp = root(x, parents), root(y, parents)
    if xp == yp:
        return
    parents[xp] = yp

# Same checks if two nodes are in the same group in Union-Find.
def same(x, y, parents):
    return root(x, parents) == root(y, parents)

# Root finds the root of the node in Union-Find.
def root(x, parents):
    if parents[x] == x:
        return x
    parents[x] = root(parents[x], parents)
    return parents[x]

# TrialDivision returns the result of prime factorization of integer N.
# Complicity: O(n)
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

# IsPrime judges whether an argument integer is a prime number or not.
def is_prime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Main function
def main():
    n, x = map(int, read_string().split())
    A = read_int_slice(n)
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

if __name__ == "__main__":
    main()
