import sys

INF = 0x5fffffff
a = [0] * 100002
b = [0] * 100002

def getint():
    n = 0
    if p[0] == '-':
        p = p[1:]
        while p[0] >= '0':
            n = (n << 3) + (n << 1) + ord(p[0]) - ord('0')
            p = p[1:]
        return -n
    while p[0] >= '0':
        n = (n << 3) + (n << 1) + ord(p[0]) - ord('0')
        p = p[1:]
    return n

# Read input from stdin
input_data = sys.stdin.read()
p = input_data.split()

w = getint()

ans = 0
f = 0
close = INF

for i in range(1, w + 1):
    k = getint()
    p = p[1:]

    if k == 0:
        f |= 1
        continue

    if k < 0:
        if f < 0 or close - (i - f) > -k:
            close = -k
            f = i
        if f < 0:
            f = -2

    ans += k

if ans == 0 or (f & 1) == 0:
    print(0)
    sys.exit(0)

if (f & 2) == 0:
    print(ans)
    sys.exit(0)

for close in [0] * (w + 1):
    f = w
    for i in range(w, 0, -1):
        if a[i] == 0:
            close = INF
            f = -1
            continue

        if a[i] < 0:
            if f < 0 or close - (f - i) > -a[i]:
                close = -a[i]
                f = i

        else:
            b[i] = INF
            if f >= 0:
                k = close - (f - i)
                if k < 0:
                    k = 0
                b[i] = k

for close in [0] * (w + 1):
    f = w
    for i in range(1, w + 1):
        if a[i] > 0:
            if b[i] > a[i]:
                ans += a[i]
            else:
                ans += b[i]

print(ans)
