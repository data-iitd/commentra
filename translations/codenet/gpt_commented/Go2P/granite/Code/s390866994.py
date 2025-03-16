
import sys

# Function to print output to the console
def out(*x):
    print(*x)

# Scanner for reading input from standard input
sc = iter(sys.stdin.read().split())

# Function to read an integer from input
def getInt():
    return int(next(sc))

# Function to read a string from input
def getString():
    return next(sc)

# Basic utility functions for mathematical operations
def max(a, b):
    return a if a > b else b

def min(a, b):
    return a if a < b else b

def asub(a, b):
    return abs(a - b)

def abs(a):
    return a if a >= 0 else -a

# Main function
def main():
    # Read the number of elements (N), maximum count (C), and time limit (K)
    N, C, K = getInt(), getInt(), getInt()
    t = [getInt() for _ in range(N)] # Create a list to hold the time values

    t.sort() # Sort the time values in ascending order

    # Initialize variables for counting groups and tracking the end time
    ans = 1 # Start with one group
    cnt = 1 # Count of elements in the current group
    end = t[0] + K # Calculate the end time for the first group

    # Iterate through the sorted time values
    for i in range(1, N):
        # Check if we can add the current time to the current group
        if cnt < C and t[i] <= end:
            cnt += 1 # Increment the count of the current group
        else:
            # Start a new group since the current time exceeds the end time
            cnt = 1 # Reset the count for the new group
            end = t[i] + K # Update the end time for the new group
            ans += 1 # Increment the group count

    out(ans) # Output the total number of groups formed

# Call the main function
main()

