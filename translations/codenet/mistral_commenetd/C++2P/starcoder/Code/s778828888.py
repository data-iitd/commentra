
n, m, x = map(int, input().split())
a = [0] * (n + 1)
for i in range(m):
    a[int(input())] = 1
ansl = ansr = i = 0
for i in range(x, n + 1):
    ansr += a[i]
for i in range(x, -1, -1):
    ansl += a[i]
print(min(ansl, ansr))

