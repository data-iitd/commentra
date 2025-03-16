
import sys

def main():
    n = int(input())
    a = []
    b = []
    left = sys.maxsize
    right = 0
    for i in range(n):
        x, y = map(int, input().split())
        a.append(x)
        b.append(y)
        left = min(left, x)
        right = max(right, y)
    for i in range(n):
        if a[i] == left and b[i] == right:
            print(i + 1)
            return
    print(-1)

if __name__ == "__main__":
    main()

