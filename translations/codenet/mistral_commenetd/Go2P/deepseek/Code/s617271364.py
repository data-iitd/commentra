import sys

# Read the first line which contains the number of tests and the number of elements in the array
def input():
    return sys.stdin.readline().strip()

# Initialize the global variables
N, A, B, C = map(int, input().split())

# Initialize the array
arr = [int(input()) for _ in range(N)]

# Function to calculate the minimum cost
def dfs(dp, times, arr):
    global ans
    # Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
    if times >= N:
        ans = min(ans, calc(dp, arr))
        return

    # Recursive case: try all possible values for the current element
    for i in range(4):
        dp[times] = i
        dfs(dp, times + 1, arr)

# Function to calculate the cost
def calc(dp, arr):
    # Initialize the cost and the variables to store the sum of elements with each value in dp
    cost = 0
    AA = 0
    BB = 0
    CC = 0

    # Initialize the memo array to store the number of elements with each value in dp
    memo = [0] * 4

    # Iterate through the dp array and update the variables
    for i in range(len(dp)):
        # Update the variables based on the current value in dp
        a = dp[i]
        memo[a] += 1
        if a == 1:
            AA += arr[i]
        elif a == 2:
            BB += arr[i]
        elif a == 3:
            CC += arr[i]

    # Calculate the cost based on the variables
    cost += abs(A - AA) + abs(B - BB) + abs(C - CC)

    # Update the cost based on the number of elements with each value in dp
    for i in range(1, 4):
        a = memo[i]
        if a < 1:
            cost += 10000
        else:
            cost += (a - 1) * 10

    # Return the cost
    return cost

# Initialize the answer variable
ans = 10000

# Call the dfs function to find the minimum cost
dfs([0] * N, 0, arr)

# Print the answer
print(ans)
