
import sys

def read():
    return int(input())

def write(x):
    if x < 0:
        x = -x
        sys.stdout.write('-')
    if x > 9:
        write(x // 10)
    sys.stdout.write(str(x % 10))

def writeln(x):
    write(x)
    sys.stdout.write('\n')

n = read()
m = read()
fa = [i for i in range(n + 1)]
v = [0 for i in range(n + 1)]

def get(x):
    if x == fa[x]:
        return x
    f = get(fa[x])
    v[x] += v[fa[x]]
    fa[x] = f
    return f

for i in range(1, m + 1):
    l = read()
    r = read()
    vi = read()
    li = get(l)
    ri = get(r)
    if li!= ri:
        v[ri] = vi - v[r] + v[l]
        fa[ri] = li
    else:
        if v[r] - v[l]!= vi:
            print("No")
            exit(0)

print("Yes")

