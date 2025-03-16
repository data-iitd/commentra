mod = 10**9 + 7

def check(x, a, n):
    tot = 0
    for i in range(n):
        now = a[i]
        l, r = 0, n
        if now >= 0:
            while l < r:
                c = (l + r) // 2
                if now * a[c] < x:
                    l = c + 1
                else:
                    r = c
            tot += l
        else:
            while l < r:
                c = (l + r) // 2
                if now * a[c] >= x:
                    l = c + 1
                else:
                    r = c
            tot += (n - l)
        if now * now < x:
            tot -= 1
    return tot // 2 < k

n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

INF = 10**18 + 1
l, r = -INF, INF

while l + 1 < r:
    c = (l + r) // 2
    if check(c, a, n):
        l = c
    else:
        r = c

print(l)
