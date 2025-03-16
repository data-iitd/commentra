n, m = map(int, input().split())
h = {}
for i in range(m):
    x, y = map(int, input().split())
    if x in h:
        h[x].append((y, i))
    else:
        h[x] = [(y, i)]

results = []
for k, v in h.items():
    v.sort()
    for y, i in v:
        results.append(f"{k:06d}{i+1:06d}")

print("\n".join(results))

