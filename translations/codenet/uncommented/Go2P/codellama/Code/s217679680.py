
import sys

def main():
    a, b = map(int, sys.stdin.readline().split())
    tap = 0
    consent = 1
    while consent < b:
        consent += a - 1
        tap += 1
    print(tap)

if __name__ == "__main__":
    main()

