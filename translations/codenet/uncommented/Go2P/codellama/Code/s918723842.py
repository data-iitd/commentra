
import sys

def main():
    H, W, N = map(int, sys.stdin.readline().split())

    A = max(H, W)

    print((N + A - 1) // A)

def max(a, b):
    if a < b:
        return b
    return a

if __name__ == "__main__":
    main()

