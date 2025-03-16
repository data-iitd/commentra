
import sys

def main():
    a, b, c = map(int, sys.stdin.readline().split())
    if b <= c:
        print("NO")
        return 0
    d = a
    e = d % b
    for i in range(b):
        d = d % b
        if d == c:
            print("YES")
            return 0
        elif i!= 0 and d == c:
            print("NO")
            return 0
        d += a
    print("NO")
    return 0

if __name__ == "__main__":
    main()

