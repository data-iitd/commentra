# Import necessary libraries
import sys

# Global variables
N, ss, ans, A, B, C = 0, 0, 10000, 0, 0, 0

# Function to read the next line from input
def next_line():
    return sys.stdin.readline().strip()

# Function to calculate the absolute value
def abs_value(a):
    return -a if a < 0 else a

# Function to calculate the minimum of two values
def min_value(a, b):
    return a if a < b else b

# Function to calculate the cost
def calc(dp, arr):
    global A, B, C
    cost = 0
    AA, BB, CC = 0, 0, 0
    memo = [0] * 4

    for i in range(len(dp)):
        a = dp[i]
        memo[a] += 1
        if a == 1:
            AA += arr[i]
        elif a == 2:
            BB += arr[i]
        elif a == 3:
            CC += arr[i]

    cost += abs_value(A - AA) + abs_value(B - BB) + abs_value(C - CC)

    for i in range(1, 4):
        a = memo[i]
        if a < 1:
            cost += 10000
        else:
            cost += (a - 1) * 10

    return cost

# Depth-first search function
def dfs(dp, times, arr):
    global ans
    if times >= N:
        ans = min_value(ans, calc(dp, arr))
        return

    for i in range(4):
        dp[times] = i
        dfs(dp, times + 1, arr)

# Main function
def main():
    global N, A, B, C, ss
    X = list(map(int, next_line().split()))
    N, A, B, C = X[0], X[1], X[2], X[3]
    ss = A + B + C

    arr = [0] * N
    dp = [0] * N

    for i in range(N):
        arr[i] = int(next_line())

    dfs(dp, 0, arr)

    print(ans)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
