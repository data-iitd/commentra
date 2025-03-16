# Import necessary modules
import sys

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to read the next line from input
def next_line():
    return sys.stdin.readline().strip()

# Function to solve the problem
def solve():
    # Read two integers N and K from input
    N, K = map(int, next_line().split())
    # Initialize a list A of size N
    A = [next_int() for _ in range(N)]
    
    # Initialize variables max_profit, max_cnt, and max_a
    max_profit = 0
    max_cnt = 0
    max_a = A[-1]
    
    # Iterate through the list A from the last index to the first index
    for i in range(N - 2, -1, -1):
        # Calculate the profit of the current transaction
        profit = max(0, max_a - A[i])
        # If the current profit is greater than the maximum profit found so far, update max_profit and max_cnt
        if max_profit < profit:
            max_profit = profit
            max_cnt = 1
        elif max_profit == profit:
            max_cnt += 1
        # Update max_a with the maximum of the current element and max_a
        max_a = max(max_a, A[i])
    
    # Print the output
    print(max_cnt)

# Entry point of the program
if __name__ == "__main__":
    solve()

# <END-OF-CODE>
