
n = int(input())
x = int(input())
l = []
for i in range(n):
    tmpL = int(input())
    l.append(tmpL)
tmpSum = 0
rs = 0
for i, v in enumerate(l):
    tmpSum += v
    if i >= n:
        rs = n
        break
    if tmpSum <= x:
        rs = i + 2
    else:
        break
print(rs)
