n = int(input())
a = list(map(int, input().split()))

t = 0
for i in range(n):
    s = 0
    for j in range(1, n):
        if j <= i:
            continue
        m = a[i] * a[j]
        s += m
    t += s

print(t)
# <END-OF-CODE>
