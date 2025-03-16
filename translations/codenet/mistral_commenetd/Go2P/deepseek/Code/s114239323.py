import sys
import math

# Helper function to read a single string from standard input
def next_string():
    return input().strip()

# Helper function to read a single integer from standard input
def next_int():
    return int(input().strip())

# Helper function to read an array of N integers from standard input
def next_ints(n):
    return list(map(int, input().strip().split()))

# Helper function to calculate the maximum of integers
def max_int(a):
    return max(a)

# Helper function to calculate the minimum of integers
def min_int(a):
    return min(a)

# Helper function to calculate the sum of integers
def sum_int(a):
    return sum(a)

# Helper function to calculate the absolute difference of integers
def abs_diff(a):
    return abs(a)

# Main function
def main():
    # Read the number of test cases N from standard input
    N = next_int()

    # Read an array h of N integers from standard input
    h = next_ints(N)

    # Initialize a dp array of size N with zeros
    dp = [0] * N

    # Set the first element of dp to the absolute difference between the first and second elements of h
    dp[1] = abs(h[0] - h[1])

    # Iterate over the array h from the second element to the last
    for i in range(2, N):
        # Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]))

    # Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
    print(dp[-1])

# Call the main function
if __name__ == "__main__":
    main()
