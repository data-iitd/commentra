# Input Function
def nextint():
    c = input()
    while c!= '-' and (c < '0' or c > '9'):
        c = input()
    s = c == '-'
    if s:
        c = input()
    x = 0
    while c >= '0' and c <= '9':
        x = x * 10 + ord(c) - ord('0')
        c = input()
    return -x if s else x

# Global Variables
n = 0
a = []
e1 = []
e2 = []
d = []
b = []

# Function Definitions
def p(a, b):
    if a < b:
        return a + b * n
    else:
        return b + a * n

def f(from):
    if b[from]:
        return -1
    if d[from]:
        return d[from]
    b[from] = True
    to = e1[from]
    max = 0
    if to!= 0:
        now = f(to)
        if now < 0:
            return now
        if now > max:
            max = now
    to = e2[from]
    if to!= 0:
        now = f(to)
        if now < 0:
            return now
        if now > max:
            max = now
    b[from] = False
    return d[from] = max + 1

# Main Function
n = nextint()
for i in range(n):
    a.append([])
    for j in range(n - 1):
        a[i].append(nextint() - 1)
for i in range(n):
    for j in range(n - 2):
        from_ = p(i, a[i][j])
        to = p(i, a[i][j + 1])
        if e1[from_] == 0:
            e1[from_] = to
        elif e2[from_] == 0:
            e2[from_] = to
        else:
            print(-1)
            exit(0)
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

