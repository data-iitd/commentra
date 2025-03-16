import sys
import math
from collections import deque

MOD = 10**9 + 7

def get_int():
    return int(sys.stdin.readline().strip())

def get_int_array(n):
    return list(map(int, sys.stdin.readline().strip().split()))

def get_string():
    return sys.stdin.readline().strip()

def get_string_array(n):
    return [get_string() for _ in range(n)]

def abs_val(a):
    return abs(a)

def pow_mod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = pow_mod(n, p // 2)
        return calc_mod(t * t)
    else:
        return calc_mod(n * pow_mod(n, p - 1))

def calc_mod(x):
    return x % MOD

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

def calc_gcd(x, y):
    if y == 0:
        return x
    return calc_gcd(y, x % y)

def get_divisor(n):
    divisor = set()
    divisor.add(1)
    if n != 1:
        divisor.add(n)

    sqrt_n = int(math.sqrt(n))
    for i in range(2, sqrt_n + 1):
        if n % i == 0:
            divisor.add(i)
            divisor.add(n // i)

    return list(divisor)

def main():
    N = get_int()

    if N % 10 in {2, 4, 5, 7, 9}:
        print("hon")
    elif N % 10 in {0, 1, 6, 8}:
        print("pon")
    elif N % 10 == 3:
        print("bon")

# Graph class and its methods
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
        if v not in visited:
            dfs(v, edges, visited)

def bfs(c, graph):
    next_nodes = deque([c])
    visited = set()

    while next_nodes:
        u = next_nodes.popleft()
        visited.add(u)

        for v in graph.edges[u]:
            if v not in visited:
                # Do something with v if needed
                next_nodes.append(v)

if __name__ == "__main__":
    main()

