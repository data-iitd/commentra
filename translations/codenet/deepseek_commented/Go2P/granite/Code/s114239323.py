
import sys

def nextInt():
    return int(next(tokens))

def nextInts(N):
    return [nextInt() for _ in range(N)]

def main():
    N = nextInt()
    h = nextInts(N)
    dp = [0] * N
    dp[1] = abs(h[0] - h[1])
    for i in range(2, N):
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]))
    print(dp[N - 1])

if __name__ == '__main__':
    tokens = iter(sys.stdin.read().split())
    main()

