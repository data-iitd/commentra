
import sys

def nextint():
    return int(sys.stdin.read(1))

n = nextint()
a = [[0] * (n - 1) for _ in range(n)]
for i in range(n):
    for j in range(n - 1):
        a[i][j] = nextint() - 1

e1 = [0] * (n * n)
e2 = [0] * (n * n)
d = [0] * (n * n)
b = [False] * (n * n)

def f(from_):
    if b[from_]:
        return -1
    if d[from_]!= 0:
        return d[from_]
    b[from_] = True
    to = e1[from_]
    max_ = 0
    if to!= 0:
        now = f(to)
        if now < 0:
            return now
        if now > max_:
            max_ = now
    to = e2[from_]
    if to!= 0:
        now = f(to)
        if now < 0:
            return now
        if now > max_:
            max_ = now
    b[from_] = False
    return d[from_] = max_ + 1

ans = 0
for i in range(n):
    for j in range(n - 2):
        from_ = i * n + a[i][j]
        to = i * n + a[i][j + 1]
        if e1[from_] == 0:
            e1[from_] = to
        elif e2[from_] == 0:
            e2[from_] = to
        else:
            print(-1)
            exit()
for i in range(n):
    from_ = i * n + a[i][0]
    now = f(from_)
    if now < 0:
        ans = -1
        break
    if now > ans:
        ans = now
print(ans)

