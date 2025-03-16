
import sys

N = 100000
INF = 1000000

class Date:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

def root(b):
    count = 0
    d = [INF] * N
    d[0] = 0
    flag = True
    while flag:
        flag = False
        for i in range(b):
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]
                flag = True
    return d

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    a = []
    for i in range(n):
        u, k = map(int, sys.stdin.readline().split())
        for j in range(k):
            go, cost = map(int, sys.stdin.readline().split())
            a.append(Date(go, u, cost))
    d = root(len(a))
    for i in range(n):
        print(i, d[i])

