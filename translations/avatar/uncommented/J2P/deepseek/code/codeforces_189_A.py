import sys

def main():
    n = int(input().strip())
    a = int(input().strip())
    b = int(input().strip())
    c = int(input().strip())
    
    arr = [a, b, c]
    dp = [float('-inf')] * (4010)
    dp[0] = 0
    
    for i in range(3):
        for j in range(arr[i], len(dp)):
            dp[j] = max(dp[j], dp[j - arr[i]] + 1)
    
    print(dp[n])

if __name__ == "__main__":
    main()
