import sys

def max_left(n):
    return n - 2 if n > 2 else 0

def main():
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        n = int(sys.stdin.readline().strip())
        print(max_left(n))

if __name__ == "__main__":
    main()
