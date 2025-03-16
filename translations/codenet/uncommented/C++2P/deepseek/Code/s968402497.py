tc, n, m = map(int, input().split())
if n > m:
    n, m = m, n
fl = 0
for i in range(1, m + 1):
    if i * tc >= n and i * tc <= m:
        print("OK")
        fl = 1
        break
if fl == 0:
    print("NG")

