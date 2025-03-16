import sys

def merge(a, n, l, m, r):
    n1 = m - l
    n2 = r - m
    L = [None] * (n1 + 1)
    R = [None] * (n2 + 1)
    for i in range(n1):
        L[i] = a[l + i]
    for i in range(n2):
        R[i] = a[m + i]
    L[n1].v = 2000000000
    R[n2].v = 2000000000
    i = 0
    j = 0
    for k in range(l, r):
        if L[i].v <= R[j].v:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1

def merge_sort(a, n, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        merge_sort(a, n, l, m)
        merge_sort(a, n, m, r)
        merge(a, n, l, m, r)

def partition(a, n, p, r):
    x = a[r]
    i = p - 1
    for j in range(p, r):
        if a[j].v <= x.v:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1

def quick_sort(a, n, p, r):
    if p < r:
        q = partition(a, n, p, r)
        quick_sort(a, n, p, q - 1)
        quick_sort(a, n, q + 1, r)

n = int(sys.stdin.readline().strip())
a = [None] * n
b = [None] * n

for i in range(n):
    s, v = sys.stdin.readline().strip().split()
    a[i] = Card(s, int(v))
    b[i] = Card(s, int(v))

merge_sort(a, n, 0, n)
quick_sort(b, n, 0, n - 1)

stable = True
for i in range(n):
    if a[i].s != b[i].s:
        stable = False

if stable:
    print("Stable")
else:
    print("Not stable")

for card in b:
    print(card.s, card.v)

