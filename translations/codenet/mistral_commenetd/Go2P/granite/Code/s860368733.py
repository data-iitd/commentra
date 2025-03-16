

n, m = map(int, input().split())
h = list(map(int, input().split()))
counter = {}
for i in range(m):
    a, b = map(int, input().split())
    if h[a-1] < h[b-1]:
        counter[a] = True
    elif h[a-1] > h[b-1]:
        counter[b] = True
    elif h[a-1] == h[b-1]:
        counter[a] = True
        counter[b] = True
print(n - len(counter))
