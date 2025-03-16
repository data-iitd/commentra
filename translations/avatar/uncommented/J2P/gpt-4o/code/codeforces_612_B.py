def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    dp = [0] * 200001
    
    for i in range(n):
        dp[int(data[i + 1])] = i
    
    ans = 0
    for i in range(2, n + 1):
        ans += abs(dp[i] - dp[i - 1])
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
