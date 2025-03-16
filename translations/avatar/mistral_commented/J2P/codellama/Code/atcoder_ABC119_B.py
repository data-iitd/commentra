
import sys
import math

def solve(x, u):
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x)))

if __name__ == "__main__":
    N = int(sys.stdin.readline().strip())
    x = [float(sys.stdin.readline().strip()) for _ in range(N)]
    u = [sys.stdin.readline().strip() for _ in range(N)]
    print(solve(x, u))

