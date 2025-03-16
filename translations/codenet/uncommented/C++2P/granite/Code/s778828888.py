
n, m, x = map(int, input().split())
a = [0] * (n + 1)
for _ in range(m):
    a[int(input())] = 1

ansl = 0
for i in range(x, n + 1):
    ansl += a[i]
ansr = 0
for i in range(x, 0, -1):
    ansr += a[i]

print(min(ansl, ansr))
