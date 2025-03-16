
import sys

def read():
    x = 0
    f = 1
    ch = sys.stdin.read(1)
    while ch < '0' or ch > '9':
        if ch == '-':
            f = -1
        ch = sys.stdin.read(1)
    while ch >= '0' and ch <= '9':
        x = x * 10 + ord(ch) - ord('0')
        ch = sys.stdin.read(1)
    return x * f

def write(x):
    if x < 0:
        sys.stdout.write('-')
        x = -x
    if x >= 10:
        write(x // 10)
    sys.stdout.write(str(x % 10))

def writeln(x):
    write(x)
    sys.stdout.write('\n')

n = read()
a = [0] * (n + 1)
q = [0] * (n + 1)
tot = 0
for i in range(1, n + 1):
    a[i] = read()
a.sort()
for i in range(1, n + 1):
    if i < n and a[i] == a[i + 1]:
        q[tot + 1] = a[i]
        tot += 1
        i += 1
writeln(q[tot] * q[tot - 1])

