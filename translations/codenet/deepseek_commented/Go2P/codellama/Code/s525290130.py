
import sys

def nextInt(sc):
    sc.next()
    return int(sc.next())

def reva(b):
    for i in range(len(b)/2):
        b[i], b[len(b)-1-i] = b[len(b)-1-i], b[i]

def main():
    sc = sys.stdin
    n = nextInt(sc)
    a = [nextInt(sc) for i in range(n)]
    q = nextInt(sc)
    for i in range(q):
        b = nextInt(sc)
        e = nextInt(sc)
        reva(a[b:e])
    wtr = sys.stdout
    for i in range(n):
        if i > 0:
            wtr.write(" ")
        wtr.write(str(a[i]))
    wtr.write("\n")

