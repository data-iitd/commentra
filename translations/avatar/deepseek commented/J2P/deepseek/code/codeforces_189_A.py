def main():
    # Read three integers from the user
    n = int(input())
    maxn = 4010
    a, b, c = map(int, input().split())
    
    # Store the coin values in a list
    arr = [a, b, c]
    
    # Initialize a dp array with all elements set to negative infinity
    dp = [float('-inf')] * maxn
    
    # Set the base case where dp[0] is 0
    dp[0] = 0
    
    # Iterate over the coin values and update the dp array
    for i in range(3):
        for j in range(arr[i], len(dp)):
            dp[j] = max(dp[j], dp[j - arr[i]] + 1)
    
    # Print the value of dp[n]
    print(dp[n])

main()
