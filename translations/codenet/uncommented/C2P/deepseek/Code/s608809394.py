n = int(input())
a = list(map(int, input().split()))
t = 0
for i in range(n):
    s = 0
    for j in range(1, n):
        if j <= i:
            continue
        m = a[i] * a[j]
        s = s + m
    t = t + s
print(t)
