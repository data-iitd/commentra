
n, m = map(int, input().split())
h = {}
for i in range(m):
    x, y = map(int, input().split())
    if x not in h:
        h[x] = [(x, y, i)]
    else:
        h[x].append((x, y, i))

results = [None] * m
for k, v in h.items():
    v.sort(key=lambda x: x[1])
    for idx, ci in enumerate(v):
        results[ci[2]] = f"{ci[0]:06d}{idx + 1:06d}"

print("\n".join(results))

