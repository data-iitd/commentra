

# Read an integer from standard input
def read():
    k = 0
    f = 1
    ch = input()
    while ch < '0' or ch > '9':
        if ch == '-':
            f = -1
        ch = input()
    while ch >= '0' and ch <= '9':
        k = k * 10 + ch - '0'
        ch = input()
    return k * f

# Write an integer to standard output
def write(x):
    if x < 0:
        x = -x
    if x > 9:
        write(x // 10)
    print(x % 10, end='')

# Write an integer and a newline to standard output
def writeln(x):
    write(x)
    print()

# Initialize variables
n = read()
m = read()
v = [0] * (n + 1)
fa = [i for i in range(n + 1)]

# Get the root of a tree
def get(x):
    if fa[x] == x:
        return x
    f = get(fa[x])
    v[x] += v[fa[x]]
    fa[x] = f
    return f

# Main function
for i in range(1, m + 1):
    l = read()
    r = read()
    vi = read()
    li = get(l)
    ri = get(r)
    if li!= ri:
        v[ri] += vi - v[r] + v[l]
        fa[ri] = li
    else:
        if v[r] - v[l]!= vi:
            print("No")
            exit(0)
print("Yes")

