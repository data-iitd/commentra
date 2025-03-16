
import sys

def findpar(x):
    if par[x] == x:
        return x
    par[x] = findpar(par[x])
    return par[x]

def unite(x, y):
    x = findpar(x)
    y = findpar(y)
    if x == y:
        return
    par[x] = y

def main():
    n = int(input())
    node = []
    for i in range(n):
        x, y = map(int, input().split())
        node.append((x, y, i))
    node.sort(key=lambda x: x[0])
    e = []
    for i in range(1, n):
        e.append((node[i - 1][2], node[i][2], node[i][0] - node[i - 1][0]))
    node.sort(key=lambda x: x[1])
    for i in range(1, n):
        e.append((node[i - 1][2], node[i][2], node[i][1] - node[i - 1][1]))
    e.sort(key=lambda x: x[2])
    par = list(range(n))
    ans = 0
    for u, v, val in e:
        if findpar(u) == findpar(v):
            continue
        unite(u, v)
        ans += val
    print(ans)

if __name__ == "__main__":
    main()

