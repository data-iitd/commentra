import sys

N = 100000
INF = 1000000

class Date:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

def root(b, n, a):
    d = [INF] * n
    d[0] = 0
    flag = 1

    while flag != 0:
        flag = 0
        for i in range(b):
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]
                flag = 1
    return d

def main():
    n = int(sys.stdin.readline().strip())
    a = []
    for i in range(n):
        u, k = map(int, sys.stdin.readline().strip().split())
        for j in range(k):
            go, cost = map(int, sys.stdin.readline().strip().split())
            a.append(Date(go, u, cost))
    
    d = root(len(a), n, a)
    for i in range(n):
        print(f"{i} {d[i]}")

if __name__ == "__main__":
    main()
