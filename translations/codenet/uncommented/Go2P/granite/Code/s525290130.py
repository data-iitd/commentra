
import sys

def nextInt(sc):
    return int(sc.readline())

def reva(b):
    for i in range(len(b) // 2):
        b[i], b[len(b) - 1 - i] = b[len(b) - 1 - i], b[i]

def main():
    sc = bufio.Scanner(sys.stdin)
    n = nextInt(sc)
    a = [nextInt(sc) for _ in range(n)]
    q = nextInt(sc)
    for _ in range(q):
        b = nextInt(sc)
        e = nextInt(sc)
        reva(a[b:e])
    print(*a)

if __name__ == "__main__":
    main()

