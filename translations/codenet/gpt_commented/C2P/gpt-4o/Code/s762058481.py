# Function to return the minimum of two integers
def chmin(a, b):
    if a > b:
        return b  # Return b if it is smaller than a
    else:
        return a  # Otherwise, return a

def main():
    # Read the number of elements (n) from standard input
    n = int(input())
    
    # Declare lists for dynamic programming and heights
    dp = [10000] * n  # dp[i] will hold the minimum cost to reach step i
    h = list(map(int, input().split()))  # Read the heights of each step from standard input

    # Base case: the cost to reach the first step is 0
    dp[0] = 0

    # Fill the dp array with the minimum costs to reach each step
    for i in range(1, n):
        # Calculate the cost to reach step i from step i-1 and step i-2
        if i == 1:
            dp[1] = abs(h[1] - h[0])  # Cost to jump from step 0 to step 1
        else:
            # Choose the minimum cost between jumping from step i-1 or i-2
            dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), 
                          dp[i - 2] + abs(h[i] - h[i - 2]))

    # Output the minimum cost to reach the last step
    print(dp[n - 1])

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
