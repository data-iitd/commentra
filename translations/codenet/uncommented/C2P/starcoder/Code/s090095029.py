
n, m = map(int, raw_input().split())
r0 = [False] * n
for i in range(m):
    a, b = map(int, raw_input().split())
    if a > b:
        a, b = b, a
    if a == 1:
        r0[b - 1] = True
    if b == n:
        r1.append(a - 1)
res = False
for i in r1:
    if r0[i]:
        res = True
print "POSSIBLE" if res else "IMPOSSIBLE"

