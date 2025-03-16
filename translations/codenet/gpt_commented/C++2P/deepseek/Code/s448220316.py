def read_int():
    k = 0
    f = 1
    ch = getchar()
    while ch < '0' or ch > '9':
        if ch == '-':
            f = -1
        ch = getchar()
    while ch >= '0' and ch <= '9':
        k = k * 10 + ord(ch) - ord('0')
        ch = getchar()
    return k * f

def write(x):
    if x < 0:
        x = -x
        putchar('-')
    if x > 9:
        write(x // 10)
    putchar(x % 10 + ord('0'))

def writeln(x):
    write(x)
    putchar('\n')

def get(x):
    if x == fa[x]:
        return x
    f = get(fa[x])
    v[x] += v[fa[x]]
    fa[x] = f
    return fa[x]

n = read_int()
m = read_int()
fa = [i for i in range(n + 1)]
v = [0] * (2 * m + 1)

for _ in range(m):
    l = read_int()
    r = read_int()
    vi = read_int()
    li = get(l)
    ri = get(r)
    if li != ri:
        v[ri] = vi - v[r] + v[l]
        fa[ri] = li
    else:
        if v[r] - v[l] != vi:
            print("No")
            exit()

print("Yes")
