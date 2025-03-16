
import sys

def initialize(n):
    global par, rank
    par = [i for i in range(n)]
    rank = [0 for i in range(n)]

def root(i):
    if par[i] == i:
        return i
    par[i] = root(par[i])
    return par[i]

def same(i, j):
    return root(i) == root(j)

def unite(i, j):
    i = root(i)
    j = root(j)
    if i == j:
        return
    if rank[i] < rank[j]:
        par[i] = j
    else:
        par[j] = i
        if rank[i] == rank[j]:
            rank[i] += 1

def main():
    n, m = map(int, sys.stdin.readline().split())
    p = list(map(int, sys.stdin.readline().split()))
    initialize(n)
    for i in range(m):
        x, y = map(int, sys.stdin.readline().split())
        unite(x-1, y-1)
    s = 0
    for i in range(n):
        if same(i, p[i]):
            s += 1
    print(s)

if __name__ == "__main__":
    main()

