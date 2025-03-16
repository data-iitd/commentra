
while True:
    n, r = map(int, input().split())
    if n == 0 and r == 0:
        break
    a = list(range(1, n + 1))
    for _ in range(r):
        p, c = map(int, input().split())
        b = a[-p-c+1:]
        a[-p-c+1:] = a[-p:]
        a[-p:] = b
    print(a[-1])

