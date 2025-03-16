n, m = map(int, input().split())
h = list(map(int, input().split()))
a, b = map(int, input().split())

counter = {}

for i in range(m):
    if h[a-1] < h[b-1]:
        counter[a] = 1
    elif h[a-1] > h[b-1]:
        counter[b] = 1
    elif h[a-1] == h[b-1]:
        counter[a] = 1
        counter[b] = 1

print(n - len(counter))

