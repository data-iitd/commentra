

MOD = 10 ** 9 + 7

def run():
 cs = input()
 dp = [[0] * 13 for _ in range(len(cs))]
 base = 1
 for i in range(len(cs) - 1, -1, -1):
 if cs[i] == '?':
 for pre in range(13):
 for next in range(10):
 dp[i][(base * next + pre) % 13] += (dp[i + 1][pre] if i < len(cs) - 1 else (pre == 0))
 dp[i][(base * next + pre) % 13] %= MOD
 else:
 next = int(cs[i])
 for pre in range(13):
 dp[i][(base * next + pre) % 13] += (dp[i + 1][pre] if i < len(cs) - 1 else (pre == 0))
 dp[i][(base * next + pre) % 13] %= MOD
 base = base * 10 % 13
 print(dp[0][5])

run()

