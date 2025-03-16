
a = []
r = []
map = {}
for i in range(5):
    a.append(int(input()))
    r.append(a[i] % 10)
    if r[i]!= 0:
        map[10 - r[i]] = a[i]
ans = 0
if len(map) == 0:
    for i in range(5):
        ans += a[i]
    print(ans)
    return
last = map[max(map.keys())]
idx = 0
for i in range(5):
    if a[i] == last:
        idx = i
for i in range(5):
    if i!= idx:
        if r[i] == 0:
            ans += a[i]
        else:
            ans += a[i] + (10 - r[i])
ans += last
print(ans)
