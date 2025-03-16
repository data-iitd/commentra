
n, m = map(int, input().split())
h = list(map(int, input().split()))
counter = set()
for _ in range(m):
    a, b = map(int, input().split())
    if h[a-1] < h[b-1]:
        counter.add(a)
    elif h[a-1] > h[b-1]:
        counter.add(b)
    else:
        counter.add(a)
        counter.add(b)
print(n - len(counter))
