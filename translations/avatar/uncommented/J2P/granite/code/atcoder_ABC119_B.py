
import sys

def solve(x, u):
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x)))

if __name__ == "__main__":
    N = int(input())
    x = [float(x) for x in input().split()]
    u = input().split()
    print(solve(x, u))