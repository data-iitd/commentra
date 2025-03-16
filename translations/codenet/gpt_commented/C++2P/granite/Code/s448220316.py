
import sys

# Function to read an integer from input
def read():
    k = 0
    f = 1
    ch = sys.stdin.read(1)
    while ch < '0' or ch > '9':
        if ch == '-':
            f = -1
        ch = sys.stdin.read(1)
    while ch >= '0' and ch <= '9':
        k = k * 10 + ord(ch) - ord('0')
        ch = sys.stdin.read(1)
    return k * f

# Function to write an integer to output
def write(x):
    if x < 0:
        x = -x
        sys.stdout.write('-')
    if x > 9:
        write(x // 10)
    sys.stdout.write(str(x % 10))

# Function to write an integer followed by a newline
def writeln(x):
    write(x)
    sys.stdout.write('\n')

# Global variables for number of nodes, edges, and other parameters
n = read()
m = read()
l = 0
r = 0
vi = 0
fa = [0] * (n + 1)
v = [0] * (n + 1)

# Function to find the representative of a set and update the value
def get(x):
    if x == fa[x]:
        return x
    f = get(fa[x])
    v[x] += v[fa[x]]
    return fa[x] = f

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

