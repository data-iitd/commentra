import sys

def nextint():
    return int(sys.stdin.readline().strip())

n = nextint()
a = [list(map(lambda x: int(x) - 1, sys.stdin.readline().strip().split())) for _ in range(n)]

def p(a, b):
    if a < b:
        return a + b * n
    else:
        return b + a * n

e1 = [0] * 1000000
e2 = [0] * 1000000
d = [0] * 1000000
b = [False] * 1000000

def f(from_index):
    if b[from_index]:
        return -1
    if d[from_index]:
        return d[from_index]
    
    b[from_index] = True
    max_value = 0
    
    to = e1[from_index]
    if to != 0:
        now = f(to)
        if now < 0:
            return now
        if now > max_value:
            max_value = now
    
    to = e2[from_index]
    if to != 0:
        now = f(to)
        if now < 0:
            return now
        if now > max_value:
            max_value = now
    
    b[from_index] = False
    d[from_index] = max_value + 1
    return d[from_index]

for i in range(n):
    for j in range(n - 1):
        from_index = p(i, a[i][j])
        to_index = p(i, a[i][j + 1])
        if e1[from_index] == 0:
            e1[from_index] = to_index
        elif e2[from_index] == 0:
            e2[from_index] = to_index
        else:
            print(-1)
            sys.exit(0)

ans = 0
for i in range(n):
    from_index = p(i, a[i][0])
    now = f(from_index)
    if now < 0:
        ans = -1
        break
    if now > ans:
        ans = now

print(ans)

# <END-OF-CODE>
