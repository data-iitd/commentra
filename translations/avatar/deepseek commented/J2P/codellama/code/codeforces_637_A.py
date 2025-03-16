import sys

n = int(sys.stdin.readline())
ara = list(map(int, sys.stdin.readline().split()))
map = {}

for i in range(n):
    if ara[i] not in map:
        map[ara[i]] = 1
    else:
        map[ara[i]] += 1

max = 0
for i in map.values():
    max = max(max, i)

mm = {}
for i in range(n):
    if ara[i] not in mm:
        mm[ara[i]] = 1
        if mm[ara[i]] == max:
            print(ara[i])
            break
    else:
        mm[ara[i]] += 1
        if mm[ara[i]] == max:
            print(ara[i])
            break

# 