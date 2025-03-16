
import sys

def cmp1(a, b):
    return a[0] < b[0]

def cmp2(a, b):
    return a[1] < b[1]

def init():
    global par
    for i in range(n + 1):
        par[i] = i

def findpar(x):
    if par[x] == x:
        return x
    else:
        par[x] = findpar(par[x])
        return par[x]

def unite(x, y):
    x = findpar(x)
    y = findpar(y)
    if x == y:
        return
    par[x] = y

def main():
    global n, par, e
    n = int(sys.stdin.readline())
    init()
    node = []
    for i in range(1, n + 1):
        x, y = map(int, sys.stdin.readline().split())
        node.append((x, y, i))
    node.sort(cmp1)
    cnt = 0
    for i in range(2, n + 1):
        e.append((node[i - 1][2], node[i][2], node[i][0] - node[i - 1][0]))
        cnt += 1
    node.sort(cmp2)
    for i in range(2, n + 1):
        e.append((node[i - 1][2], node[i][2], node[i][1] - node[i - 1][1]))
        cnt += 1
    e.sort()
    ans = 0
    for i in range(cnt):
        u, v, val = e[i]
        if findpar(u) == findpar(v):
            continue
        unite(u, v)
        ans += val
    print(ans)

if __name__ == "__main__":
    main()
    # 