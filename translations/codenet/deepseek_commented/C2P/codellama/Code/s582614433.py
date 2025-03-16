#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long

#define rep(i, l, r) for (ll i = (l); i < (r); i++)

#define repp(i, l, r, k) for (ll i = (l); i < (r); i += (k))

#define INF ((1LL << 62) - (1LL << 31))

#define max(p, q) ((p) > (q) ? (p) : (q))

#define min(p, q) ((p) < (q) ? (p) : (q))

#define bit(n, m) (((n) >> (m)) & 1)

def upll(a, b):
    return a < b ? -1 : a > b ? 1 : 0

def downll(a, b):
    return a < b ? 1 : a > b ? -1 : 0

def sortup(a, n):
    a.sort(key=lambda x: x, reverse=False)

def sortdown(a, n):
    a.sort(key=lambda x: x, reverse=True)

def pom(a, n, m):
    x = 1
    a %= m
    for i in range(n):
        if n & 1:
            x = x * a % m
        a = a * a % m
    return x

#define MOD 1000000007

def invp(a, p):
    return pom(a, p - 2, p)

class E:
    def __init__(self, p, i, s):
        self.p = p
        self.i = i
        self.s = s

def esort(a, b):
    p = a
    q = b
    cmp = strcmp(p.s, q.s)
    if cmp:
        return cmp
    if p.p < q.p:
        return 1
    return -1

data = []

n = 0
m = 0

def main():
    # Read the number of edges
    global n
    n = int(input())

    # Read each edge's string and long long value, and store the index
    global data
    data = []
    rep(i, 0, n)
        s = input()
        p = int(input())
        data.append(E(p, i, s))

    # Sort the edges using qsort and the custom esort function
    global data
    data.sort(key=lambda x: x, reverse=False)

    # Print the indices of the edges in the sorted order
    rep(i, 0, n)
        print(data[i].i + 1)

if __name__ == "__main__":
    main()

