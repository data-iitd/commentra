

n, k = map(int, input().split())
arr = list(map(int, input().split()))
o, e = 0, 0
for i in range(n):
    if arr[i] == 1:
        o += 1
    else:
        e += 1
res = []
for i in range(k):
    l, r = map(int, input().split())
    if (r - l + 1) % 2 == 1:
        res.append("0")
    else:
        if (r - l + 1) // 2 <= o and (r - l + 1) // 2 <= e:
            res.append("1")
        else:
            res.append("0")
print("\n".join(res))
