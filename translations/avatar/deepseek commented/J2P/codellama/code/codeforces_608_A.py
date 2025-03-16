
import sys

def main():
    n = int(sys.stdin.readline())
    s = int(sys.stdin.readline())
    max = 0

    for i in range(n):
        f, t = map(int, sys.stdin.readline().split())
        if max < f + t:
            max = f + t

    print(max if max > s else s)

if __name__ == "__main__":
    main()

