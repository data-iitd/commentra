n, k = map(int, input().split())
p = list(map(int, input().split()))

# Selection sort
for i in range(n):
    l = i
    for j in range(i + 1, n):
        if p[j] < p[l]:
            l = j
    if l != i:
        p[i], p[l] = p[l], p[i]

o = sum(p[i] for i in range(k))
print(o)

# <END-OF-CODE>
