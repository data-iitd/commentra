I = 10000

def counting_sort(a, b, k):
    c = [0] * (I + 1)
    for j in range(k):
        c[a[j]] += 1
    for i in range(1, I + 1):
        c[i] += c[i - 1]
    for j in range(k - 1, -1, -1):
        b[c[a[j]] - 1] = a[j]
        c[a[j]] -= 1

n = int(input())
a = [0] * (n + 1)
b = [0] * (n + 1)

for i in range(1, n + 1):
    a[i] = int(input())

counting_sort(a, b, n)

print(b[1], end='')
for i in range(2, n + 1):
    print(f" {b[i]}", end='')
print()
