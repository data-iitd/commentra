
import sys

def main():
    n = int(sys.stdin.readline())
    x = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    v = a[:]
    ans = 1000000000
    for k in range(n):
        kans = 0
        for i in range(n):
            if i - k < 0:
                v[i] = min(v[i], a[n + i - k])
            else:
                v[i] = min(v[i], a[i - k])
            kans += v[i]
        ans = min(ans, kans + k * x)

    print(ans)

if __name__ == "__main__":
    main()

