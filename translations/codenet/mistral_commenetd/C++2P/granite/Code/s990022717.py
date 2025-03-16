
import sys

def main():
    n, k, x, y = map(int, sys.stdin.readline().split())
    sum = 0
    for i in range(1, n + 1):
        if i > k:
            sum += y
        else:
            sum += x
    print(sum)

if __name__ == "__main__":
    main()

