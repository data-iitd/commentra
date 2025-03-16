
import sys

def main():
    n = int(sys.stdin.readline())
    solve(n)

def solve(n):
    # Calculating the result based on the given logic
    print((n // 3) * 2 + (n % 3 == 0) * 1)

if __name__ == "__main__":
    main()

