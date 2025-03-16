import sys

# Global variables to store input values
N, ss, ans, A, B, C = 0, 0, 10000, 0, 0, 0

# Function to read the next line of input
def next_line():
    return sys.stdin.readline().strip()

# Function to calculate the minimum of two values
def min_value(a, b):
    return a if a < b else b

# Function to calculate the absolute value
def abs_value(a):
    return -a if a < 0 else a

# Depth-first search function to explore different combinations of choices
def dfs(dp, times, arr):
    global ans
    if times >= N:
        ans = min_value(ans, calc(dp, arr))
        return

    for i in range(4):
        dp[times] = i
        dfs(dp, times + 1, arr)

# Function to calculate the cost based on the chosen combinations
def calc(dp, arr):
    cost = 0
    AA, BB, CC = 0, 0, 0

    # Create a memoization array to count the occurrences of each choice
    memo = [0] * 4
    for i in range(len(dp)):
        memo[dp[i]] += 1
        if dp[i] == 1:
            AA += arr[i]
        elif dp[i] == 2:
            BB += arr[i]
        elif dp[i] == 3:
            CC += arr[i]

    cost += abs_value(A - AA) + abs_value(B - BB) + abs_value(C - CC)

    # Add additional cost for each choice that appears more than once
    for i in range(1, 4):
        a = memo[i]
        if a < 1:
            cost += 10000
        else:
            cost += (a - 1) * 10

    return cost

# Main function to execute the program
def main():
    global N, A, B, C, ss, ans

    # Read the input values for N, A, B, and C
    X = list(map(int, next_line().split()))
    N, A, B, C = X[0], X[1], X[2], X[3]

    # Initialize the array to store the values and a dp array for choices
    arr = [0] * N
    dp = [0] * N
    ss = A + B + C

    # Read the array values from input
    for i in range(N):
        a = int(next_line())
        arr[i] = a

    # Start the depth-first search to find the minimum cost
    dfs(dp, 0, arr)

    # Print the minimum cost found
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
