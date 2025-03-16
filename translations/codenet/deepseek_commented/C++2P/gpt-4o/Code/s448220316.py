import sys

def read():
    return int(sys.stdin.readline().strip())

def write(x):
    sys.stdout.write(str(x))

def writeln(x):
    write(x)
    sys.stdout.write("\n")

n = read()
m = read()

fa = list(range(n + 1))
v = [0] * (2 * n + 1)

def get(x):
    if x == fa[x]:
        return x
    f = get(fa[x])
    v[x] += v[fa[x]]
    fa[x] = f
    return f

for _ in range(m):
    l = read()
    r = read()
    vi = read()
    
    li = get(l)
    ri = get(r)
    
    if li != ri:
        v[ri] = vi - v[r] + v[l]
        fa[ri] = li
    else:
        if v[r] - v[l] != vi:
            print("No")
            sys.exit(0)

print("Yes")
# <END-OF-CODE>
