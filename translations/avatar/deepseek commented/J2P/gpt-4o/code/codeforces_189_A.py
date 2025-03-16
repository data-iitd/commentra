def main():
    # Initialize a list to read input from the user
    n = int(input())
    maxn = 4010
    a = int(input())
    b = int(input())
    c = int(input())
    
    # Store the coin values in a list
    arr = [a, b, c]
    
    # Initialize a dp list with all elements set to -float('inf')
    dp = [-float('inf')] * maxn
    
    # Set the base case where dp[0] is 0
    dp[0] = 0
    
    # Iterate over the coin values and update the dp list
    for i in range(3):
        for j in range(arr[i], len(dp)):
            dp[j] = max(dp[j], dp[j - arr[i]] + 1)
    
    # Print the value of dp[n]
    print(dp[n])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
