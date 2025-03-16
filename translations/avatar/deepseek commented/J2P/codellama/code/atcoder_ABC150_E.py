import sys

def main():
    n = int(sys.stdin.readline().strip())
    c = list(map(int, sys.stdin.readline().strip().split()))
    if n == 1:
        print(c[0] * 2 % 1000000007)
        return
    c.sort()

    b = 2 ** n
    a = 2 ** (n - 2)
    ans = 0
    for i in range(2, n + 2):
        val = a * i % 1000000007
        val *= c[n + 1 - i]
        val %= 1000000007
        ans += val
        ans %= 1000000007
    ans *= b
    ans %= 1000000007
    print(ans)

if __name__ == "__main__":
    main()

