
# Initialize scanner for input and writer for output
sc = input
wtr = output

# Declare global variables
N, ss, ans, A, B, C = 0, 0, 10000, 0, 0, 0

def main():
    # Read input values and split them into a slice of strings
    X = sc().split()

    # Parse the first four values from the input
    N, A, B, C = int(X[0]), int(X[1]), int(X[2]), int(X[3])

    # Initialize arrays for dynamic programming and results
    arr = [0] * N
    dp = [0] * N
    ans = 10000
    ss = A + B + C

    # Read N integers from input and populate the array
    for i in range(N):
        arr[i] = int(sc())

    # Perform depth-first search to find the optimal distribution
    dfs(dp, 0, arr)

    # Output the final answer
    wtr(ans)

# Recursive function to explore all distributions of items
def dfs(dp, times, arr):
    # Base case: if all items have been considered
    if times >= N:
        ans = min(ans, calc(dp, arr))
        return

    # Explore all possible distributions (0 to 3)
    for i in range(4):
        dp[times] = i
        dfs(dp, times + 1, arr)

# Calculate the cost of the current distribution
def calc(dp, arr):
    cost, AA, BB, CC = 0, 0, 0, 0

    # Count items in each group and calculate their sums
    memo = [0] * 4
    for i in range(len(dp)):
        memo[dp[i]] += 1
        if dp[i] == 1:
            AA += arr[i]
        elif dp[i] == 2:
            BB += arr[i]
        elif dp[i] == 3:
            CC += arr[i]

    # Calculate the cost based on the differences from target values
    cost += abs(A - AA) + abs(B - BB) + abs(C - CC)

    # Penalize for missing groups and excess items
    for i in range(1, 4):
        a = memo[i]
        if a < 1:
            cost += 10000
        else:
            cost += (a - 1) * 10

    return cost

# Helper function to find the minimum of two integers
def min(a, b):
    if a < b:
        return a
    return b

# Helper function to find the absolute value of an integer
def abs(a):
    if a < 0:
        return a * -1
    return a

# Additional utility functions and types can be defined below


Translate the above Python code to C++ and end with comment "