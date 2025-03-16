n, m = map(int, input().split())
s = []
c = []
for _ in range(m):
    si, ci = map(int, input().split())
    s.append(si - 1)
    c.append(ci)

for i in range(1000):
    st = str(i)
    if len(st) != n:
        continue
    f = 1
    for j in range(m):
        if st[s[j]] == str(c[j]):
            pass
        else:
            f = 0
            break
    if f:
        print(i)
        break
else:
    print(-1)
