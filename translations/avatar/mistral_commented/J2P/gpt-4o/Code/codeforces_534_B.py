import numpy as np  # Importing numpy for array manipulation

def main():
    # Reading input variables from the user
    v1 = int(input())  # Reading the first integer value
    v2 = int(input())  # Reading the second integer value
    t = int(input())   # Reading the number of time steps
    d = int(input())   # Reading the maximum difference between two consecutive values

    dp = np.full((t - 1, 1150), -float('inf'))  # Creating a 2D array dp of size (t-1) x 1150 initialized to negative infinity

    # Initializing the first row of the dp table with the given value
    for i in range(t - 1):
        dp[i][v1] = v1  # Setting the value of the cell (i, v1) to v1

    total_sum = 0  # Initializing a variable total_sum to 0

    # Filling the dp table using dynamic programming
    for i in range(1, t - 1):
        for j in range(1150):
            for x in range(d + 1):
                if j + x < 1150:  # Ensure we don't go out of bounds
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j)  # Filling the current cell with the maximum value
            for x in range(d + 1):
                if j - x >= 0:  # Ensure we don't go out of bounds
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j)  # Filling the current cell with the maximum value
        total_sum += dp[i][1149]  # Adding the value of the last cell of the current row to the total_sum

    ans = -float('inf')  # Initializing a variable ans with negative infinity

    # Finding the maximum value that can be obtained by jumping from any cell in the last but one row to the last row
    for j in range(1150):
        if abs(j - v2) <= d:  # Checking if the absolute difference between j and v2 is less than or equal to d
            ans = max(ans, dp[t - 2][j] + v2)  # Updating the value of ans

    print(ans)  # Printing the final answer

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
