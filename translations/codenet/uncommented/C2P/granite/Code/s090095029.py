
import sys

def main():
    n, m = map(int, input().split())
    r0 = [False] * n
    r1 = []
    for _ in range(m):
        a, b = map(int, input().split())
        if a > b:
            a, b = b, a
        if a == 1:
            r0[b - 1] = True
        if b == n:
            r1.append(a - 1)
    res = any(r0[i] for i in r1)
    print("POSSIBLE" if res else "IMPOSSIBLE")

if __name__ == "__main__":
    main()

