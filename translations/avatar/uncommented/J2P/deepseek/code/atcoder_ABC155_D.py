MOD = int(1e9 + 7)
DX = [-1, 0, 1, 0]
DY = [0, -1, 0, 1]

def check(x, a, k):
    tot = 0
    n = len(a)
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

def main():
    fs = list(map(int, input().split()))
    n = fs[0]
    k = fs[1]
    a = list(map(int, input().split()))
    a.sort()
    INF = int(1e18) + 1
    l, r = -INF, INF
    while l + 1 < r:
        c = (l + r) // 2
        if check(c, a, k):
            l = c
        else:
            r = c
    print(l)

if __name__ == "__main__":
    main()
