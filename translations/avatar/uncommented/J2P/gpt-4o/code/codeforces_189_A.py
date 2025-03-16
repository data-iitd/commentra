def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    maxn = 4010
    a = int(data[1])
    b = int(data[2])
    c = int(data[3])
    arr = [a, b, c]
    dp = [float('-inf')] * maxn
    dp[0] = 0
    
    for i in range(3):
        for j in range(arr[i], len(dp)):
            dp[j] = max(dp[j], dp[j - arr[i]] + 1)
    
    print(dp[n])

if __name__ == "__main__":
    main()
# <END-OF-CODE>
