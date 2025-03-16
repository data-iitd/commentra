import sys

def nextint():
    c = sys.stdin.read(1)
    while c != '-' and (c < '0' or c > '9'):
        c = sys.stdin.read(1)
    s = False
    if c == '-':
        s = True
        c = sys.stdin.read(1)
    x = 0
    while '0' <= c and c <= '9':
        x = x * 10 + c - '0'
        c = sys.stdin.read(1)
    return -x if s else x

n = nextint()
a = [[0] * (n - 1) for _ in range(n)]
for i in range(n):
    for j in range(n - 1):
        a[i][j] = nextint() - 1

e1 = [0] * 1000000
e2 = [0] * 1000000
d = [0] * 1000000
b = [False] * 1000000

def p(a, b):
    return a + b * n if a < b else b + a * n

def f(from_):
    if b[from_]:
        return -1
    if d[from_]:
        return d[from_]
    b[from_] = True
    to = e1[from_]
    max_ = 0
    if to != 0:
        now = f(to)
        if now < 0:
            return now
        if now > max_:
            max_ = now
    to = e2[from_]
    if to != 0:
        now = f(to)
        if now < 0:
            return now
        if now > max_:
            max_ = now
    b[from_] = False
    return d[from_] = max_ + 1

ans = 0
for i in range(n):
    from_ = p(i, a[i][0])
    now = f(from_)
    if now < 0:
        ans = -1
        break
    if now > ans:
        ans = now

print(ans)
