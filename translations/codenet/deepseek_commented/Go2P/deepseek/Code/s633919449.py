import sys
import math
from collections import deque

initialBufSize = 10000
maxBufSize = 1000000
mod = 10**9 + 7

sys.setrecursionlimit(10**7)

input = sys.stdin.readline

# The main function reads an integer N and prints "hon" if the last digit of N is 2, 4, 5, 7, or 9,
# "pon" if it is 0, 1, 6, or 8, and "bon" if it is 3. This part of the code handles simple conditional logic
# based on the last digit of N.
def main():
    N = int(input().strip())

    match N % 10:
        case 2 | 4 | 5 | 7 | 9:
            print("hon")
        case 0 | 1 | 6 | 8:
            print("pon")
        case 3:
            print("bon")

# The Graph class and its methods define a graph with n nodes and edges.
# The dfs function performs depth-first search, and the bfs function performs breadth-first search.
# These functions are useful for graph traversal and can be used for various graph-related problems.
class Graph:
    def __init__(self, n):
        self.n = n
        self.edges = [[] for _ in range(n)]

    def add_edge(self, u, v):
        self.edges[v].append(u)
        self.edges[u].append(v)

def dfs(c, edges, visited):
    visited.add(c)

    for v in edges[c]:
        if v in visited:
            continue
        dfs(v, edges, visited)

def bfs(c, graph):
    next_queue = deque([c])
    visited = set([c])

    while next_queue:
        u = next_queue.popleft()
        for v in graph.edges[u]:
            if v in visited:
                continue

            # なにか処理

            next_queue.append(v)
            visited.add(v)

# Utility functions are defined for converting strings to integers, calculating absolute values, finding powers,
# and checking primality. These functions enhance code reusability and readability.
def get_int():
    return int(input().strip())

def get_int_array(n):
    return [get_int() for _ in range(n)]

def get_string():
    return input().strip()

def get_string_array(n):
    return [get_string() for _ in range(n)]

def abs_val(a):
    return abs(a)

def pow_val(p, q):
    return p**q

def pow_mod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = pow_mod(n, p // 2)
        return (t * t) % mod
    else:
        return (n * pow_mod(n, p - 1)) % mod

def min_val(*nums):
    return min(nums)

def max_val(*nums):
    return max(nums)

def str_search(a, b):
    return b in a

def print_int_array(array):
    print(array)

def calc_mod(x):
    return x % mod

def reverse_string(s):
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
    length = 2**len(nums)
    result = [[]]

    for num in nums:
        new_subsets = [subset + [num] for subset in result]
        result.extend(new_subsets)

    return result

def calc_gcd(x, y):
    while y != 0:
        x, y = y, x % y
    return x

def get_divisors(n):
    divisors = {1}
    divisors.add(n)

    sqrt_n = int(math.sqrt(n))
    for i in range(2, sqrt_n + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)

    return list(divisors)

class IntHeap(list):
    def __init__(self):
        super().__init__()

    def push(self, x):
        self.append(x)
        self._upheap(len(self) - 1)

    def pop(self):
        if len(self) == 1:
            return self[0]
        top = self[0]
        self[0] = self[-1]
        self.pop()
        self._downheap(0)
        return top

    def _upheap(self, pos):
        endpos = len(self)
        startpos = pos
        newitem = self[pos]
        childpos = 2 * pos + 1
        while childpos < endpos:
            rightpos = childpos + 1
            if rightpos < endpos and not self[childpos] > self[rightpos]:
                childpos = rightpos
            self[pos] = self[childpos]
            pos = childpos
            childpos = 2 * pos + 1
        self[pos] = newitem
        self._fixup(startpos, pos)

    def _downheap(self, pos):
        endpos = len(self)
        newitem = self[pos]
        childpos = 2 * pos + 1
        while childpos < endpos:
            rightpos = childpos + 1
            if rightpos < endpos and not self[childpos] > self[rightpos]:
                childpos = rightpos
            self[pos] = self[childpos]
            pos = childpos
            childpos = 2 * pos + 1
        self[pos] = newitem
        self._fixdown(pos)

    def _fixup(self, startpos, pos):
        parentpos = (pos - 1) // 2
        while pos > startpos:
            if self[pos] > self[parentpos]:
                self[pos], self[parentpos] = self[parentpos], self[pos]
                pos = parentpos
                parentpos = (pos - 1) // 2
            else:
                break

    def _fixdown(self, pos):
        endpos = len(self)
        childpos = 2 * pos + 1
        while childpos < endpos:
            rightpos = childpos + 1
            if rightpos < endpos and not self[childpos] > self[rightpos]:
                childpos = rightpos
            self[pos], self[childpos] = self[childpos], self[pos]
            pos = childpos
            childpos = 2 * pos + 1

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
    return (fact_n * (fact_kr * fact_nkr) % mod) % mod

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

