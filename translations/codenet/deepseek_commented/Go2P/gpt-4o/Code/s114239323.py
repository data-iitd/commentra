import sys

# Reads the next integer from the input
def next_int():
    return int(next(reader))

# Reads a list of integers of length N
def next_ints(N):
    return [int(next(reader)) for _ in range(N)]

# Utility function to find the absolute value of an integer
def abs_value(a):
    return -a if a < 0 else a

# Utility function to find the minimum value in a list of integers
def min_value(a):
    return min(a)

# Main function to solve the problem
def main():
    global reader
    reader = iter(sys.stdin.read().split())
    
    # Reads the number of steps N
    N = next_int()  # Reads the number of steps N
    
    # Reads the list of heights h
    h = next_ints(N)  # Reads the list of heights h
    
    # Initializes the DP array with zeros
    dp = [0] * N  # Initializes the DP array with zeros
    
    # Sets the cost to reach the second step
    dp[1] = abs_value(h[0] - h[1])  # Sets the cost to reach the second step
    
    # Computes the minimum cost to reach each step using dynamic programming
    for i in range(2, N):
        dp[i] = min_value([dp[i - 1] + abs_value(h[i] - h[i - 1]),
                           dp[i - 2] + abs_value(h[i] - h[i - 2])])
    
    # Prints the minimum cost to reach the last step
    print(dp[N - 1])  # Prints the minimum cost to reach the last step

if __name__ == "__main__":
    main()

# <END-OF-CODE>
