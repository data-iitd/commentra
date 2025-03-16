
import sys

def main():
    n = int(input())
    solve(n)

def solve(n):
    print((n // 3) * 2 + (n % 3 == 0 and 0 or 1))

if __name__ == "__main__":
    main()

