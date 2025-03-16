import sys

mod = int(1e9 + 7)
DX = [-1, 0, 1, 0]
DY = [0, -1, 0, 1]
n = 0
k = 0
a = []

def check(x):
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
        if a[i] * a[i] < x:
            tot -= 1
    return tot // 2 < k

def main():
    global n, k, a
    n = int(sys.stdin.readline().strip())
    k = int(sys.stdin.readline().strip())
    a = list(map(int, sys.stdin.readline().strip().split()))
    
    a.sort()
    INF = int(1e18) + 1
    l, r = -INF, INF
    
    while l + 1 < r:
        c = (l + r) // 2
        if check(c):
            l = c
        else:
            r = c
            
    print(l)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
