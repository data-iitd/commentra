import sys

def main():
    # Read four integers from input: initial velocity (v1), final velocity (v2), time (t), and maximum change in velocity (d)
    v1 = int(input())
    v2 = int(input())
    t = int(input())
    d = int(input())
    
    # Initialize a 2D array dp to store the maximum values for each time step and velocity
    dp = [[-sys.maxsize] * 1150 for _ in range(t - 1)]
    
    # Set the initial state for the first time step with the initial velocity
    dp[0][v1] = v1
    
    # Variable to accumulate the maximum sum of velocities
    sum = 0
    
    # Iterate through each time step from 1 to t-2
    for i in range(1, t - 1):
        # Iterate through each possible velocity
        for j in range(1150):
            # Update the dp array for increasing velocities
            for x in range(d + 1):
                if j + x < 1150:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j)
            # Update the dp array for decreasing velocities
            for x in range(d + 1):
                if j - x >= 0:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j)
    
    # Variable to store the final answer, initialized to the smallest possible value
    ans = -sys.maxsize
    
    # Iterate through the last time step to find the maximum achievable velocity close to v2
    for i in range(t - 2, t - 1):
        for j in range(1150):
            # Check if the current velocity is within the allowed range of v2
            if abs(j - v2) <= d:
                ans = max(ans, dp[i][j] + v2)
    
    # Output the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
