
n = int(input())
ara = list(map(int, input().split()))
map = {}
for i in range(n):
    v = ara[i]
    if v not in map:
        map[v] = 1
    else:
        map[v] += 1
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

