
import sys

def nextInt():
    return int(input())

def reva(b):
    for i in range(len(b) // 2):
        b[i], b[len(b) - 1 - i] = b[len(b) - 1 - i], b[i]

def main():
    n = nextInt()
    a = [nextInt() for _ in range(n)]
    q = nextInt()
    for _ in range(q):
        b = nextInt()
        e = nextInt()
        reva(a[b:e])
    print(*a, sep=" ")

if __name__ == "__main__":
    main()

