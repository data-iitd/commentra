
n, x = map(int, input().split())
l = list(map(int, input().split()))
tmpSum = 0
rs = 0
for i, v in enumerate(l):
    tmpSum += v
    if tmpSum <= x:
        rs = i + 2
    elif tmpSum > x:
        break
print(rs)

