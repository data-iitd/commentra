
# Package main is the entry point of the program
import sys

# scan function is used to read one line at a time
sc = sys.stdin.readline

# Global variables
N, ss, ans, A, B, C = map(int, sc().split())

# sort function is used to sort an array in ascending order
# def sort(a):
#     return sorted(a)

def main():
    # Read the next N lines which contain the elements of the array
    arr = [int(sc()) for _ in range(N)]

    # Initialize the array and the dp array
    dp = [0] * N

    # Initialize the answer variable
    ans = 10000

    # Call the dfs function to find the minimum cost
    dfs(dp, 0, arr)

    # Print the answer
    print(ans)

# dfs function is used for depth-first search
def dfs(dp, times, arr):
    # Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
    if times >= N:
        ans = min(ans, calc(dp, arr))
        return

    # Recursive case: try all possible values for the current element
    for i in range(4):
        dp[times] = i
        dfs(dp, times+1, arr)

# calc function is used to calculate the cost
def calc(dp, arr):
    # Initialize the cost and the variables to store the sum of elements with each value in dp
    cost, AA, BB, CC = 0, 0, 0, 0

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

# Helper functions
def min(a, b):
    if a < b:
        return a
    return b

def max(a, b):
    if a > b:
        return a
    return b

def com(a, b):
    if a > b:
        return 0
    return 0 #abs(a - b)

def abs(a):
    if a < 0:
        return a * -1
    return a

def sum(a):
    return sum(a)

