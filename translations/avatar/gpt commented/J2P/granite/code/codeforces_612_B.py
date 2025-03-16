
import sys

def main():
    # Read the number of elements to be processed
    n = int(input())
    
    # Initialize a dp array to store the indices of the input elements
    dp = [0] * (200001)
    
    # Populate the dp array with the indices of the input elements
    for i in range(n):
        # Read the next integer and store its index in the dp array
        dp[int(input())] = i
    
    # Initialize a variable to accumulate the result
    ans = 0
    
    # Calculate the total distance between consecutive elements in the dp array
    for i in range(2, n + 1):
        # Add the absolute difference of indices of consecutive elements to ans
        ans += abs(dp[i] - dp[i - 1])
    
    # Output the final result
    print(ans)

if __name__ == "__main__":
    main()

