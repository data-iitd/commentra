
# Python 3 program to find the number of ways to select
# k elements from a set of n elements

# Function to find the number of ways to select
# k elements from a set of n elements
def findWays(n, k):
    # dp[i] stores the number of ways to select
    # i elements from a set of n elements
    dp = [0 for i in range(n + 1)]

    # Base case: one way to select zero elements
    dp[0] = 1

    # Map to store the last occurrence of each number
    kek = {}

    # Map to store the previous index of each number
    prev = {}

    # Fill the dynamic programming array
    for i in range(1, n + 1):

        # Update dp[i] based on previous values and occurrences
        dp[i] = dp[i - 1] + (prev.get(i - 1)!= i - 1 and kek.get(i - 1)!= None)

        # Apply modulus to avoid overflow
        dp[i] %= MOD

        # Update the last occurrence
        kek[i - 1] = dp[i]

        # Update the previous index
        prev[i - 1] = i

    return dp[n]

# Driver Code
if __name__ == '__main__':
    n = 5
    k = 3
    print(findWays(n, k))

