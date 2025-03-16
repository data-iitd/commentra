
while True:
    n, r = map(int, input().split())
    if n == 0 and r == 0:
        break
    a = list(range(n, 0, -1))
    for _ in range(r):
        p, c = map(int, input().split())
        b = a[:]
        for i in range(c):
            a[i] = b[p-1+i]
        for i in range(c, c+p-1):
            a[i] = b[i-c]
    print(a[0])

