import sys

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to solve the problem
def solve():
    N = next_int()  # Read number of elements
    _ = next_int()  # Ignore the second value
    A = [next_int() for _ in range(N)]  # Read each element into the list

    max_profit = 0  # Initialize maximum profit
    max_cnt = 0     # Initialize count of maximum profit occurrences
    max_a = A[-1]   # Start with the last element as the maximum

    for i in range(N - 2, -1, -1):  # Iterate backwards through the list
        profit = max(0, max_a - A[i])  # Calculate profit based on the current element
        if max_profit < profit:  # If we found a new maximum profit
            max_profit = profit  # Update maximum profit
            max_cnt = 1          # Reset count to 1
        elif max_profit == profit:  # If we found another occurrence of the maximum profit
            max_cnt += 1  # Increment the count
        max_a = max(max_a, A[i])  # Update the maximum element seen so far

    print(max_cnt)  # Output the count of maximum profit occurrences

# Main function to execute the program
if __name__ == "__main__":
    solve()  # Call the solve function

# <END-OF-CODE>
