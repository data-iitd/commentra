
import sys

def main():
    a, b = map(int, sys.stdin.readline().split())
    c = 0
    while a >= 1 and b >= 1:
        if a >= b:
            b += 1
            a -= 2
        else:
            a += 1
            b -= 2
        c += 1
    print(c)

if __name__ == "__main__":
    main()

