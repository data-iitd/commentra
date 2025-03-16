
import sys

n, m = map(int, sys.stdin.readline().split())
h = {}
for i in range(m):
    x, y = map(int, sys.stdin.readline().split())
    if x not in h:
        h[x] = [{'prefecture': x, 'year': y, 'position': i}]
    else:
        h[x].append({'prefecture': x, 'year': y, 'position': i})

results = []
for _, v in h.items():
    v.sort(key=lambda x: x['year'])
    for idx, ci in enumerate(v):
        results.append(f"{ci['prefecture']:06d}{idx+1:06d}")

print("\n".join(results))

