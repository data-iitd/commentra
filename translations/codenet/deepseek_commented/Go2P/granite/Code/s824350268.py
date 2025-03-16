

import sys
import math

def main():
    N = int(input())
    sqrtN = int(math.sqrt(N))

    min_sum = N
    for i in range(1, sqrtN + 1):
        if N % i!= 0:
            continue

        num = i + (N // i) - 2
        if num < min_sum:
            min_sum = num

    print(min_sum)

class Graph:
    def __init__(self, n):
        self.n = n
        self.edges = [[] for _ in range(n)]

    def add_edge(self, u, v):
        self.edges[v].append(u)
        self.edges[u].append(v)

def dfs(c, edges, visited):
    visited[c] = True

    for v in edges[c]:
        if not visited[v]:
            dfs(v, edges, visited)

def get_int():
    return int(input())

def get_string():
    return input()

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

def min(*nums):
    if len(nums) == 0:
        raise ValueError("function min() requires at least one argument.")

    res = nums[0]
    for num in nums:
        res = min(res, num)

    return res

def max(*nums):
    if len(nums) == 0:
        raise ValueError("function max() requires at least one argument.")

    res = nums[0]
    for num in nums:
        res = max(res, num)

    return res

def str_search(a, b):
    return b in a

def print_int_array(array):
    print("[" + ", ".join(map(str, array)) + "]")

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

if __name__ == "__main__":
    main()

