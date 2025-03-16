import sys

def main():
    n = int(sys.stdin.readline())
    c = list(map(int, sys.stdin.readline().split()))
    mod = 1000000007
    if n == 1:
        print((c[0] * 2) % mod)
        return
    c.sort()
    b = 1
    for i in range(n):
        b = (b * 2) % mod
    a = 1
    for i in range(n - 2):
        a = (a * 2) % mod
    ans = 0
    for i in range(2, n + 1):
        val = a * i % mod
        val = val * c[n + 1 - i] % mod
        ans = (ans + val) % mod
    ans = (ans * b) % mod
    print(ans)

if __name__ == "__main__":
    main()

