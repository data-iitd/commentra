import sys
import collections

n = int(sys.stdin.readline())
map = collections.defaultdict(int)

while n > 0:
    num = int(sys.stdin.readline())
    if map[num] == 0:
        map[num] += 1
    else:
        key = map.keys()[map[num] - 1]
        map[key] -= 1
        if map[key] == 0:
            del map[key]
        map[num] += 1
    n -= 1

ans = 0
for key in map.keys():
    ans += map[key]

print(ans)

