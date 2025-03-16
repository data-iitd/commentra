import sys

def main():
    n = int(sys.stdin.readline().strip())
    dp = [0] * 200001
    values = list(map(int, sys.stdin.readline().strip().split()))
    for i in range(n):
        dp[values[i]] = i
    
    ans = 0
    for i in range(2, n + 1):
        ans += abs(dp[i] - dp[i - 1])
    
    print(ans)

if __name__ == "__main__":
    main()
