
n, k = map(int, input().split())
a = list(map(int, input().split()))
light = [0] * (n + 1)
for i in range(n):
    r, l = i - a[i], i + a[i]
    light[r if r >= 0 else 0] += 1
    light[l + 1 if l + 1 <= n else n + 1] -= 1
for i in range(1, n + 1):
    light[i] += light[i - 1]
for _ in range(k):
    tmpa = a[:]
    for i in range(n):
        a[i] = light[i + 1] - light[i - a[i]]
    for i in range(n):
        r, l = i - tmpa[i], i + tmpa[i]
        light[r if r >= 0 else 0] -= 1
        light[l + 1 if l + 1 <= n else n + 1] += 1
    for i in range(1, n + 1):
        light[i] += light[i - 1]
    is_same = True
    for i in range(n - 1):
        if a[i]!= a[i + 1]:
            is_same = False
            break
    if is_same and a[0] == n:
        break
print(*a)

