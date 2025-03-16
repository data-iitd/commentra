
import sys

while True:
    n, r = map(int, raw_input().split())
    if n == 0 and r == 0:
        break

    a = range(1, n + 1)

    for i in range(r):
        p, c = map(int, raw_input().split())

        b = a[-p:]
        a = a[:-p] + b[c:] + b[:c]

        # print a

    print a[-1]
print "---"

