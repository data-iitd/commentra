import sys
from collections import defaultdict

n = int(sys.stdin.readline().strip())
map = defaultdict(int)

for i in range(n):
    num = int(sys.stdin.readline().strip())
    if map[num] == 0:
        map[num] += 1
    else:
        key = max(map.keys(), key=lambda x: x if x < num else -1)
        map[key] -= 1
        if map[key] == 0:
            del map[key]
        map[num] += 1

ans = 0
for key in map.keys():
    ans += map[key]

print(ans)


