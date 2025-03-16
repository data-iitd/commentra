import sys

a = list(map(int, sys.stdin.readline().split()))
r = [a[i] % 10 for i in range(len(a))]
map = {}

for i in range(len(a)):
    if r[i] != 0:
        map[10 - r[i]] = a[i]

ans = 0

if len(map) == 0:
    for i in range(len(a)):
        ans += a[i]
    print(ans)
    exit()

last = map[max(map.keys())]
idx = 0

for i in range(len(a)):
    if a[i] == last:
        idx = i
        break

for i in range(len(a)):
    if i != idx:
        if a[i] % 10 == 0:
            ans += a[i]
        else:
            ans += a[i] + (10 - r[i])

ans += last

print(ans)

