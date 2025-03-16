
import sys
def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    dp = {}
    base = 0
    ans = 0
    for i in range(n):
        base = (base - a[i] % m + m) % m
        dp[base] = dp.get(base, 0) + 1
        ans += dp.get((base + a[i]) % m, 0)
    print(ans)
if __name__ == '__main__':
    main()
