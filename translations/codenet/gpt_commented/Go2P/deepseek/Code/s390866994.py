import sys
import math

# Function to print output to the console
def out(x):
    print(x)

# Function to read an integer from input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read a string from input
def get_string():
    return sys.stdin.readline().strip()

# Basic utility functions for mathematical operations
def max(a, b):
    return a if a > b else b

def min(a, b):
    return a if a < b else b

def asub(a, b):
    return a - b if a > b else b - a

def abs(a):
    return a if a >= 0 else -a

def main():
    # Read the number of elements (N), maximum count (C), and time limit (K)
    N, C, K = map(int, sys.stdin.readline().strip().split())
    t = [int(sys.stdin.readline().strip()) for _ in range(N)]

    t.sort()  # Sort the time values in ascending order

    # Initialize variables for counting groups and tracking the end time
    ans = 1  # Start with one group
    cnt = 1  # Count of elements in the current group
    end = t[0] + K  # Calculate the end time for the first group

    # Iterate through the sorted time values
    for i in range(1, N):
        # Check if we can add the current time to the current group
        if cnt < C and t[i] <= end:
            cnt += 1  # Increment the count of the current group
        else:
            # Start a new group since the current time exceeds the end time
            cnt = 1  # Reset the count for the new group
            end = t[i] + K  # Update the end time for the new group
            ans += 1  # Increment the group count

    out(ans)  # Output the total number of groups formed

