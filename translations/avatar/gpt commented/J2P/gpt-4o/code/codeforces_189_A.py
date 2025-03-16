# Import the necessary module
import sys

def main():
    # Read the total number of items (n) to be processed
    n = int(input().strip())
    
    # Define the maximum size for the dp array
    maxn = 4010
    
    # Read three integer values (a, b, c) which represent the sizes of items
    a, b, c = map(int, input().strip().split())
    
    # Store the sizes of items in a list for easier access
    arr = [a, b, c]
    
    # Initialize a dp array to store the maximum number of items that can be formed
    dp = [float('-inf')] * maxn
    
    # Base case: zero items can be formed with zero size
    dp[0] = 0
    
    # Iterate through each item size (a, b, c)
    for i in range(3):
        # Update the dp array for each possible size from the current item size
        for j in range(arr[i], len(dp)):
            # Calculate the maximum number of items that can be formed
            dp[j] = max(dp[j], dp[j - arr[i]] + 1)
    
    # Output the maximum number of items that can be formed with size n
    print(dp[n])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
