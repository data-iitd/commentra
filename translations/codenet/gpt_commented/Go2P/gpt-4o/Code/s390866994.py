import sys

# Function to print output to the console
def out(*args):
    print(*args)

# Function to read an integer from input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read a string from input
def get_string():
    return sys.stdin.readline().strip()

# Basic utility functions for mathematical operations
def max_val(a, b):
    return a if a > b else b

def min_val(a, b):
    return a if a < b else b

def asub(a, b):
    return abs(a - b)

def abs_val(a):
    return a if a >= 0 else -a

def main():
    # Read the number of elements (N), maximum count (C), and time limit (K)
    N, C, K = map(int, get_string().split())
    t = [get_int() for _ in range(N)]  # Read N time values from input

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

if __name__ == "__main__":
    main()

# <END-OF-CODE>
