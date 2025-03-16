
a, b, c, d, e = map(int, input().split())

al = [a, b, c, d, e]

for n, i in enumerate(al):
    if i == 0:
        print(n + 1)
        break

