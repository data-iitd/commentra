
while True:
    n, r = map(int, input().split())
    if n == r == 0:
        break
    a = list(range(1, n + 1))
    for _ in range(r):
        p, c = map(int, input().split())
        b = a[-p-c+1:]
        a = a[:-p-c+1] + b
        # print(a)
    print(a[-1])

