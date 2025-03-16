
import sys

def pom(a, n, m):
    x = 1
    a %= m
    while n > 0:
        if n % 2 == 1:
            x = x * a % m
        a = a * a % m
        n //= 2
    return x

def invp(a, p):
    return pom(a, p - 2, p)

# 辺の情報を個別に持つタイプ
class Edge:
    def __init__(self, p, i, s):
        self.p = p
        self.i = i
        self.s = s

n = int(input())
data = []
for i in range(n):
    s, p = input().split()
    p = int(p)
    data.append(Edge(p, i + 1, s))

data.sort(key=lambda x: (x.s, x.p))
for i in range(n):
    print(data[i].i)

