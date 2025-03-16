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
    flag = True

    while flag:
        flag = False
        for i in range(b):
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]
                flag = True
    return d

def main():
    n = int(input().strip())
    a = []
    count = 0

    for _ in range(n):
        u, k = map(int, input().strip().split())
        for _ in range(k):
            go, cost = map(int, input().strip().split())
            a.append(Date(go, u, cost))
            count += 1

    d = root(count, n, a)
    for i in range(n):
        print(i, d[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
