#define INF 1 << 30

def main():
  dp = [INF] * 101000
  dp[0] = 0
  # input
  N, K = map(int, raw_input().split())
  h = map(int, raw_input().split())

  #dp
  for i in xrange(N):
    for j in xrange(1, K + 1):
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

  # output
  print dp[N - 1]
  return 0

