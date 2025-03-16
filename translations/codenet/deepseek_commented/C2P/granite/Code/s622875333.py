
while True:
    n, r = map(int, input().split())
    if n == 0 and r == 0:
        break
    a = list(range(n, 0, -1))
    for _ in range(r):
        p, c = map(int, input().split())
        b = a[:]
        for j in range(c):
            a[j] = b[p-1+j]
        for j in range(c, c+p-1):
            a[j] = b[j-c]
    print(a[0])

