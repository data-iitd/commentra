
import sys

def main():
    n = int(sys.stdin.readline())
    c = list(map(int, sys.stdin.readline().split()))
    c.sort()
    ans = 0
    for i in range(n):
        ans = (ans + (n + 1 - i) * c[i] % 1000000007) % 1000000007
    print(ans * modpow(4, n - 1) % 1000000007)

def modpow(a, n):
    res = 1
    while n > 0:
        if n & 1 == 1:
            res = res * a % 1000000007
        a = a * a % 1000000007
        n = n >> 1
    return res

if __name__ == "__main__":
    main()

