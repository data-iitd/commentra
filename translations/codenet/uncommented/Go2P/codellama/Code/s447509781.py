
import sys

def main():
    n = int(sys.stdin.readline())
    s = [int(x) for x in sys.stdin.readline().split()]
    u = [False] * n
    m, f = 0, 0
    for c in range(1, n - 1):
        f = 0
        for k in range(0, n - 1 - c * k):
            u[k * c] = True
            if u[n - 1 - k * c]: break
            f += s[n - 1 - k * c] + s[k * c]
            if m < f: m = f
        for k in range(0, k * c < n - 1): u[k * c] = False
    print(m)

if __name__ == '__main__':
    main()

