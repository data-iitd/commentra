def main():
    import sys
    input = sys.stdin.readline
    n = int(input().split()[0])
    c = list(map(int, input().split()))

    mod = 1000000007
    if n == 1:
        print(c[0] * 2 % mod)
        return

    c.sort()

    b = power(2, n)
    a = power(2, n - 2)
    ans = 0

    for i in range(2, n + 2):
        val = a * i % mod
        val *= c[n + 1 - i]
        val %= mod
        ans += val
        ans %= mod

    ans *= b
    ans %= mod
    print(ans)


def power(x, n):
    mod = 1000000007
    if n == 0:
        return 1
    val = power(x, n // 2)
    val = val * val % mod
    if n % 2 == 1:
        val = val * x % mod
    return val


main()
