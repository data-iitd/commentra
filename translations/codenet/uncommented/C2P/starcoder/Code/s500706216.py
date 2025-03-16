n, k = map(int, input().split())
a = list(map(int, input().split()))
light = [0] * (n + 2)
for i in range(n):
    r = i - a[i]
    l = i + a[i]
    light[r < 0? 0 : r] += 1
    light[l + 1 > n? n + 1 : l + 1] -= 1
for i in range(k):
    sum = 0
    for j in range(n):
        sum += light[j]
        a[j] = sum
    for j in range(n):
        r = j - a[j]
        l = j + a[j]
        light[r < 0? 0 : r] -= 1
        light[l + 1 > n? n + 1 : l + 1] += 1
print(*a)

