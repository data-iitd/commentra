# Import necessary modules
import sys

# Function to read an integer from standard input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to read an array of N integers from standard input
def next_ints(n):
    return list(map(int, sys.stdin.readline().strip().split()))

# Function to calculate the absolute difference
def abs_value(a):
    return -a if a < 0 else a

# Function to calculate the minimum of a list
def min_value(a):
    return min(a)

# Main function
def main():
    # Read the number of test cases N from standard input
    N = next_int()

    # Read an array h of N integers from standard input
    h = next_ints(N)

    # Initialize a dp array of size N with zeros
    dp = [0] * N

    # Set the first element of dp to the absolute difference between the first and second elements of h
    dp[1] = abs_value(h[0] - h[1])

    # Iterate over the array h from the second element to the last
    for i in range(2, N):
        # Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
        dp[i] = min_value([dp[i - 1] + abs_value(h[i] - h[i - 1]), dp[i - 2] + abs_value(h[i] - h[i - 2])])

    # Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
    print(dp[N - 1])

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
