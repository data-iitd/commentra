# -*- coding: utf-8 -*-
# <START-OF-CODE>

INF = 1 << 30

def solve(N, K, h):
  dp = [INF] * (N + 1)
  dp[0] = 0

  for i in xrange(N):
    for j in xrange(1, K + 1):
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

  return dp[N - 1]

def main():
  N, K = map(int, raw_input().split())
  h = map(int, raw_input().split())
  print solve(N, K, h)

if __name__ == '__main__':
  main()

# 