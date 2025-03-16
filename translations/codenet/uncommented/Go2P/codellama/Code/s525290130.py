
import sys

def nextInt(sc):
    sc.next()
    return int(sc.next())

def reva(b):
    for i in range(len(b)/2):
        b[i], b[len(b)-1-i] = b[len(b)-1-i], b[i]

n = nextInt(sys.stdin)
a = [nextInt(sys.stdin) for i in range(n)]
q = nextInt(sys.stdin)
for i in range(q):
    b = nextInt(sys.stdin)
    e = nextInt(sys.stdin)
    reva(a[b:e])

for i in range(n):
    if i > 0:
        print " ",
    print a[i],
print

