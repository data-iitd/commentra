
import sys

N = 100000
INF = 1000000

class Date:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

def root(b):
    global d
    i = 0
    flag = True
    while flag:
        flag = False
        for i in range(b):
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]
                flag = True

if __name__ == "__main__":
    n = int(input())
    d = [INF] * n
    a = []
    count = 0
    for i in range(n):
        u, k = map(int, input().split())
        for j in range(k):
            go, cost = map(int, input().split())
            a.append(Date(go, u, cost))
            count += 1
    root(count)
    for i in range(n):
        print(i, d[i])

