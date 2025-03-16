def chmin(a, b):
    if a > b:
        return b
    else:
        return a

def main():
    n = int(input())
    dp = [10000] * n
    h = list(map(int, input().split()))

    dp[0] = 0
    for i in range(1, n):
        if i == 1:
            dp[1] = abs(h[1] - h[0])
        else:
            dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]))
    
    print(dp[n - 1])

if __name__ == "__main__":
    main()
