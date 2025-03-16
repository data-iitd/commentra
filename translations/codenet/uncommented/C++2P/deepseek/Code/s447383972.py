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

N = 200010
a = [0] * N
q = [0] * N
n = 0
tot = 0

n = read()
for i in range(1, n + 1):
    a[i] = read()

a.sort()

i = 1
while i <= n:
    if a[i] == a[i + 1]:
        q[tot] = a[i]
        tot += 1
        i += 2
    else:
        i += 1

writeln(q[tot - 1] * q[tot - 2])
