

import bufio
import math
import os
import sys

MOD = 100000007

def main():
    N = int(input())

    if N % 10 in [2, 4, 5, 7, 9]:
        print("hon")
    elif N % 10 in [0, 1, 6, 8]:
        print("pon")
    else:
        print("bon")

class Graph:
    def __init__(self, n):
        self.n = n
        self.edges = [[] for _ in range(n)]

    def add_edge(self, u, v):
        self.edges[v].append(u)
        self.edges[u].append(v)

    def dfs(self, c, visited):
        visited[c] = True

        for v in self.edges[c]:
            if not visited[v]:
                self.dfs(v, visited)

    def bfs(self, c):
        next = [c]
        visited = [False] * self.n

        while next:
            u = next.pop(0)
            visited[u] = True

            for v in self.edges[u]:
                if not visited[v]:
                    next.append(v)

def get_int():
    return int(input())

def get_int_array(n):
    return [int(input()) for _ in range(n)]

def get_string():
    return input()

def get_string_array(n):
    return [input() for _ in range(n)]

def abs(a):
    return abs(a)

def pow(p, q):
    return pow(p, q)

def pow_mod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = pow_mod(n, p // 2)
        return calc_mod(t * t)
    else:
        return calc_mod(n * pow_mod(n, p - 1))

def min(*args):
    return min(args)

def max(*args):
    return max(args)

def str_search(a, b):
    return b in a

def print_int_array(array):
    print(*array)

def calc_mod(x):
    return x % MOD

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

def powerset2(nums):
    length = 2 ** len(nums)
    result = [[] for _ in range(length)]

    index = 0
    result[index] = []
    index += 1

    for n in nums:
        max_ = index
        for i in range(max_):
            result[index] = copy_and_append(result[i], n)
            index += 1

    return result

def copy_and_append(nums, n):
    dst = nums[:]
    dst.append(n)
    return dst

def calc_gcd(x, y):
    if y == 0:
        return x
    elif x >= y:
        return calc_gcd(y, x % y)
    else:
        return calc_gcd(x, y % x)

def get_divisor(n):
    divisor = set()
    divisor.add(1)
    if n!= 1:
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
        last = self.heap.pop()
        if self.len():
            return_value = self.heap[0]
            self.heap[0] = last
            self._down(0)
            return return_value
        return last

    def _up(self, i):
        parent = (i - 1) // 2
        while i > 0 and self.less(i, parent):
            self.swap(i, parent)
            i = parent
            parent = (i - 1) // 2

    def _down(self, i):
        left = 2 * i + 1
        right = 2 * i + 2
        smallest = i
        if left < self.len() and self.less(left, smallest):
            smallest = left
        if right < self.len() and self.less(right, smallest):
            smallest = right
        if smallest!= i:
            self.swap(i, smallest)
            self._down(smallest)

def init_heap():
    ih = IntHeap()
    ih.push(0)
    return ih

def fact_mod(n):
    value = 1
    for i in range(1, n + 1):
        value = calc_mod(value * i)
    return value

def combination_mod(n, k):
    fact_n = fact_mod(n)
    fact_k = fact_mod(k)
    fact_nk = fact_mod(n - k)
    fact_kr = pow_mod(fact_k, MOD - 2)
    fact_nkr = pow_mod(fact_nk, MOD - 2)
    return calc_mod(fact_n * calc_mod(fact_kr * fact_nkr))

def prime_factors(n):
    factors = []
    i = 2
    while i * i <= n:
        r = n % i
        if r!= 0:
            i += 1
        elif r == 0:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

if __name__ == "__main__":
    main()

