
MOD = 998244353
dp = [[0 for _ in range(3001)] for _ in range(3001)]

def solve(A, B, C, D):
    dp[A][B] = 1
    for c in range(A, C + 1):
        for d in range(B, D + 1):
            if c == A and d == B:
                continue
            ans = 0
            if c > A:
                part = dp[c - 1][d]
                ans += part * d
            if d > B:
                part = dp[c][d - 1]
                ans += part * c
            if c > A and d > B:
                ans -= dp[c - 1][d - 1] * (c - 1) * (d - 1)
            dp[c][d] = (ans % MOD + MOD) % MOD
    return dp[C][D]

if __name__ == "__main__":
    A, B, C, D = map(int, input().split())
    print(solve(A, B, C, D))

