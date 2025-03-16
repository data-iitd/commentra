
import sys

def nextInt():
    return int(input())

def reva(b, e):
    for i in range(len(b) // 2):
        b[i], b[e - 1 - i] = b[e - 1 - i], b[i]

def main():
    n = nextInt()
    a = [nextInt() for _ in range(n)]
    q = nextInt()
    for _ in range(q):
        b = nextInt()
        e = nextInt()
        reva(a, e)
    print(" ".join(map(str, a)))

if __name__ == "__main__":
    main()

