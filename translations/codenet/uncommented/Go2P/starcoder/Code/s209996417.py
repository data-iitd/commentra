n, k = map(int, input().split())

x = 0
while True:
    under = k ** x
    upper = k ** (x + 1)

    if under <= n and n < upper:
        print(x + 1)
        break
    x += 1

