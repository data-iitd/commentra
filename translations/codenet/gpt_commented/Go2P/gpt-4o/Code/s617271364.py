import sys

# Initialize global variables
N, ss, ans, A, B, C = 0, 0, 10000, 0, 0, 0

def main():
    global N, A, B, C, ans, ss

    # Read input values and split them into a list of strings
    X = input().split()

    # Parse the first four values from the input
    N = int(X[0])  # Number of elements
    A = int(X[1])  # Target value A
    B = int(X[2])  # Target value B
    C = int(X[3])  # Target value C

    # Initialize arrays for dynamic programming and results
    arr = [0] * N  # Array to hold input values
    dp = [0] * N   # DP array to store current state
    ss = A + B + C  # Sum of target values

    # Read N integers from input and populate the array
    for i in range(N):
        arr[i] = int(input().strip())  # Store the integer in the array

    # Perform depth-first search to find the optimal distribution
    dfs(dp, 0, arr)

    # Output the final answer
    print(ans)

# Recursive function to explore all distributions of items
def dfs(dp, times, arr):
    global ans

    # Base case: if all items have been considered
    if times >= N:
        ans = min(ans, calc(dp, arr))  # Calculate cost and update answer
        return

    # Explore all possible distributions (0 to 3)
    for i in range(4):
        dp[times] = i  # Assign current item to one of the four groups
        dfs(dp, times + 1, arr)  # Recur for the next item

# Calculate the cost of the current distribution
def calc(dp, arr):
    cost, AA, BB, CC = 0, 0, 0, 0  # Initialize cost and group sums

    # Count items in each group and calculate their sums
    memo = [0] * 4
    for i in range(len(dp)):
        memo[dp[i]] += 1  # Count items in each group
        if dp[i] == 1:
            AA += arr[i]  # Sum for group A
        elif dp[i] == 2:
            BB += arr[i]  # Sum for group B
        elif dp[i] == 3:
            CC += arr[i]  # Sum for group C

    # Calculate the cost based on the differences from target values
    cost += abs(A - AA) + abs(B - BB) + abs(C - CC)

    # Penalize for missing groups and excess items
    for i in range(1, 4):
        a = memo[i]
        if a < 1:
            cost += 10000  # High penalty for missing group
        else:
            cost += (a - 1) * 10  # Penalty for excess items

    return cost  # Return the calculated cost

# Helper function to find the absolute value of an integer
def abs(a):
    return -a if a < 0 else a

if __name__ == "__main__":
    main()

# <END-OF-CODE>
