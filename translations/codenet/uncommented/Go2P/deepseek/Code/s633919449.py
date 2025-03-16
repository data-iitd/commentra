import sys
import math
from collections import deque

# Set up the input reader
input = sys.stdin.readline

# Constants
initialBufSize = 10000
maxBufSize = 1000000
mod = 10**9 + 7

# Helper functions
def get_int():
    return int(input().strip())

def get_ints():
    return list(map(int, input().strip().split()))

def get_string():
    return input().strip()

def get_string_array(n):
    return [input().strip() for _ in range(n)]

def abs(a):
    return int(math.fabs(a))

def pow(p, q):
    return int(math.pow(p, q))

def pow_mod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = pow_mod(n, p // 2)
        return (t * t) % mod
    else:
        return (n * pow_mod(n, p - 1)) % mod

def min(*nums):
    return min(nums)

def max(*nums):
    return max(nums)

def str_search(a, b):
    return b in a

def print_int_array(array):
    print(' '.join(map(str, array)))

def calc_mod(x):
    return x % mod

def reverse(s):
    return s[::-1]

def is_prime(n):
    if n < 2:
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False
    sqrt_n = int(math.sqrt(n))
    for i in range(3, sqrt_n + 1, 2):
        if n % i == 0:
            return False
    return True

def contains(s, e):
    return e in s

def make_range(min, max):
    return list(range(min, max + 1))

def powerset(nums):
    length = 2 ** len(nums)
    result = [[]]
    for num in nums:
        result += [subset + [num] for subset in result]
    return result

def calc_gcd(x, y):
    while y != 0:
        x, y = y, x % y
    return x

def get_divisor(n):
    divisor = {1}
    if n != 1:
        divisor.add(n)
    sqrt = int(math.sqrt(n))
    for i in range(2, sqrt + 1):
        if n % i == 0:
            divisor.add(i)
            divisor.add(n // i)
    return list(divisor)

class IntHeap:
    def __init__(self):
        self.heap = []

    def len(self):
        return len(self.heap)

    def less(self, i, j):
        return self.heap[i] > self.heap[j]

    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def push(self, x):
        self.heap.append(x)
        self._up(len(self.heap) - 1)

    def pop(self):
        if len(self.heap) == 0:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._down(0)
        return root

    def _up(self, i):
        while i > 0:
            parent = (i - 1) // 2
            if self.less(i, parent):
                self.swap(i, parent)
                i = parent
            else:
                break

    def _down(self, i):
        n = len(self.heap)
        while 2 * i + 1 < n:
            left = 2 * i + 1
            right = 2 * i + 2
            largest = left
            if right < n and self.less(right, left):
                largest = right
            if self.less(largest, i):
                self.swap(i, largest)
                i = largest
            else:
                break

def init_heap():
    return IntHeap()

def push_heap(h, n):
    h.push(n)

def pop_heap(h):
    return h.pop()

def fact_mod(n):
    value = 1
    for i in range(2, n + 1):
        value = (value * i) % mod
    return value

def combination_mod(n, k):
    fact_n = fact_mod(n)
    fact_k = fact_mod(k)
    fact_nk = fact_mod(n - k)
    fact_kr = pow_mod(fact_k, mod - 2)
    fact_nkr = pow_mod(fact_nk, mod - 2)
    return (fact_n * fact_kr * fact_nkr) % mod

def prime_factors(n):
    factors = []
    i = 2
    while i * i <= n:
        while n % i == 0:
            factors.append(i)
            n //= i
        i += 1
    if n > 1:
        factors.append(n)
    return factors

# Main logic
def main():
    N = get_int()
    if N % 10 in [2, 4, 5, 7, 9]:
        print("hon")
    elif N % 10 in [0, 1, 6, 8]:
        print("pon")
    elif N % 10 == 3:
        print("bon")

if __name__ == "__main__":
    main()
