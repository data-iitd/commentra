n, m = map(int, input().split())
h = {}
for i in range(m):
    x, y = map(int, input().split())
    if x not in h:
        h[x] = [city(x, i, y)]
    else:
        h[x].append(city(x, i, y))

results = []
for _, v in h.items():
    v.sort(key=lambda x: x.year)
    for idx, ci in enumerate(v):
        results.append(f"{ci.prefecture:06d}{idx+1:06d}")

print("\n".join(results))

# 