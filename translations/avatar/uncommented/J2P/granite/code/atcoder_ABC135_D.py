
MOD = 10**9 + 7

def run():
    s = input()
    dp = [[0]*13 for _ in range(len(s))]
    base = 1
    for i in range(len(s)):
        if s[len(s)-1-i] == '?':
            for pre in range(13):
                for next in range(10):
                    dp[i][(base*next+pre)%13] += dp[i-1][pre] if i > 0 else (1 if pre == 0 else 0)
                    dp[i][(base*next+pre)%13] %= MOD
        else:
            next = int(s[len(s)-1-i])
            for pre in range(13):
                dp[i][(base*next+pre)%13] += dp[i-1][pre] if i > 0 else (1 if pre == 0 else 0)
                dp[i][(base*next+pre)%13] %= MOD
        base = base * 10 % 13
    print(dp[len(s)-1][5])

if __name__ == "__main__":
    run()

