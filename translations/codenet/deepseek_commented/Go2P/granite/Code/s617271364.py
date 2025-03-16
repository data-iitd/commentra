
import sys
from math import *

# Scanner and Writer for efficient I/O operations
sc = bufio.Scanner(sys.stdin)
wtr = bufio.Writer(sys.stdout)

# Global variables to store input values
N, A, B, C, ans, ss = 0, 0, 0, 0, 0, 10000

# Main function to execute the program
def main():
    global N, A, B, C, ans, ss
    # Read the input values for N, A, B, and C
    X = input().split()
    N = int(X[0])
    A = int(X[1])
    B = int(X[2])
    C = int(X[3])

    # Initialize the array to store the values and a dp array for choices
    arr = [0] * N
    dp = [0] * N
    ans = 10000
    ss = A + B + C

    # Read the array values from input
    for i in range(N):
        Y = input().split()
        arr[i] = int(Y[0])

    # Start the depth-first search to find the minimum cost
    dfs(dp, 0, arr)

    # Print the minimum cost found
    print(ans)

# Depth-first search function to explore different combinations of choices
def dfs(dp, times, arr):
    global ans
    if times >= N:
        ans = min(ans, calc(dp, arr))
        return
    for i in range(4):
        dp[times] = i
        dfs(dp, times + 1, arr)

# Function to calculate the cost based on the chosen combinations
def calc(dp, arr):
    global ss
    cost = 0
    memo = [0] * 4
    for i in range(len(dp)):
        memo[dp[i]] += 1
        if dp[i] == 1:
            ss -= arr[i]
        elif dp[i] == 2:
            ss -= arr[i]
        elif dp[i] == 3:
            ss -= arr[i]
    cost += abs(A - ss) + abs(B - ss) + abs(C - ss)

    # Add additional cost for each choice that appears more than once
    for i in range(1, 4):
        a = memo[i]
        if a < 1:
            cost += 10000
        else:
            cost += (a - 1) * 10

    return cost

# Helper functions to read input, calculate minimum, and absolute value
def nextLine():
    sc.scan()
    return sc.text()

def min(a, b):
    if a < b:
        return a
    return b

def abs(a):
    if a < 0:
        return a * -1
    return a

main()
