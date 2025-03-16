#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long

#define rep(i,l,r) for(ll i=(l);i<(r);i++)

#define repp(i,l,r,k) for(ll i=(l);i<(r);i+=(k))

#define INF ((1LL<<62)-(1LL<<31))

#define max(p,q) ((p)>(q)?(p):(q))

#define min(p,q) ((p)<(q)?(p):(q))

#define bit(n,m) (((n)>>(m))&1)

def upll(a, b):
    return a < b ? -1 : a > b ? 1 : 0

def downll(a, b):
    return a < b ? 1 : a > b ? -1 : 0

def sortup(a, n):
    a.sort(key=upll)

def sortdown(a, n):
    a.sort(key=downll)

def pom(a, n, m):
    x = 1
    for a %= m:
        if n & 1:
            x = x * a % m
        a = a * a % m
        n /= 2
    return x

MOD = 1000000007

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
    if strcmp(p.s, q.s):
        return strcmp(p.s, q.s)
    if p.p < q.p:
        return 1
    return -1

data = []
n, m = 0, 0

def main():
    global n, m
    n = int(input())
    rep(i, 0, n):
        s, p = input().split()
        p = int(p)
        data.append(E(p, i, s))
    sortup(data, n)
    rep(i, 0, n):
        print(data[i].i + 1)

if __name__ == "__main__":
    main()

