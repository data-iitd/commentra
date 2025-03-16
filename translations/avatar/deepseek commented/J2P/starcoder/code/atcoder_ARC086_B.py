import sys

n = int(sys.stdin.readline())
a = [int(sys.stdin.readline()) for i in range(n)]

m = 0
for i in range(1, n):
    if abs(a[m]) < abs(a[i]):
        m = i

r = []
for i in range(n):
    if a[m] >= 0 ^ a[i] >= 0:
        r.append(str(m + 1) + " " + str(i + 1))

if a[m] >= 0:
    for i in range(1, n):
        r.append(str(i + 1) + " " + str(i + 2))
else:
    for i in range(n, 1, -1):
        r.append(str(i) + " " + str(i - 1))

print(len(r))
print("\n".join(r))

