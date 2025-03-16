import sys

def solve(x, u):
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x)))

def main():
    N = int(sys.stdin.readline())
    x = [float(sys.stdin.readline()) for _ in range(N)]
    u = [sys.stdin.readline().strip() for _ in range(N)]
    print(solve(x, u))

if __name__ == "__main__":
    main()

