
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Scanner and Writer for efficient I/O operations
var sc = bufio.NewScanner(os.Stdin)
var wtr = bufio.NewWriter(os.Stdout)

// Global variables to store input values
var N, ss, ans, A, B, C int

// Main function to execute the program
def main():
    # Read the input values for N, A, B, and C
    X = nextLine().split(" ")
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
        Y = nextLine().split(" ")
        arr[i] = int(Y[0])

    # Start the depth-first search to find the minimum cost
    dfs(dp, 0, arr)

    # Print the minimum cost found
    print(ans)
    wtr.flush()

# Depth-first search function to explore different combinations of choices
def dfs(dp, times, arr):
    if times >= N:
        ans = min(ans, calc(dp, arr))
        return

    for i in range(4):
        dp[times] = i
        dfs(dp, times + 1, arr)

# Function to calculate the cost based on the chosen combinations
def calc(dp, arr):
    cost, AA, BB, CC = 0, 0, 0, 0

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

    cost += abs(A - AA) + abs(B - BB) + abs(C - CC)

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

