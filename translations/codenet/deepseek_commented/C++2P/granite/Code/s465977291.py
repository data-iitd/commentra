
import sys

def main():
    n, d = map(int, sys.stdin.readline().split())
    a = 2 * d + 1
    print(ceil(n / a))

if __name__ == "__main__":
    main()

