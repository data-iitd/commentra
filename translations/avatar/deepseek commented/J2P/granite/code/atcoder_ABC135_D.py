
MOD = 10**9 + 7

def main():
    s = input()
    dp = [[0]*13 for _ in range(len(s))]
    base = 1
    for i in range(len(s)-1, -1, -1):
        if s[i] == '?':
            for pre in range(13):
                for next in range(10):
                    dp[i][(base*next+pre)%13] += dp[i+1][pre]
                    dp[i][(base*next+pre)%13] %= MOD
        else:
            next = int(s[i])
            for pre in range(13):
                dp[i][(base*next+pre)%13] += dp[i+1][pre]
                dp[i][(base*next+pre)%13] %= MOD
        base = base*10%13
    print(dp[0][5])

if __name__ == "__main__":
    main()

