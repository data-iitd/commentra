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
        x = x * 10 + int(ch)
        ch = sys.stdin.read(1)
    return x * f

def write(x):
    if x < 0:
        sys.stdout.write('-')
        x = -x
    if x >= 10:
        write(x // 10)
    sys.stdout.write(chr(x % 10 + ord('0')))

def writeln(x):
    write(x)
    sys.stdout.write('\n')

n = read()
a = [read() for _ in range(n)]
a.sort()
q = []
i = 0
while i < n:
    if i == n - 1 or a[i] != a[i + 1]:
        q.append(a[i])
    i += 1
if len(q) >= 2:
    writeln(q[-1] * q[-2])
