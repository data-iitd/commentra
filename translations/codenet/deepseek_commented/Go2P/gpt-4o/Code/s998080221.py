import sys
import math
from collections import defaultdict

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to read a list of integers from input
def next_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

# Main function to implement the logic
def main():
    N, _ = next_ints()
    A = next_ints()
    
    max_profit = 0
    max_count = 0
    max_a = A[-1]
    
    for i in range(N - 2, -1, -1):
        profit = max(0, max_a - A[i])
        if max_profit < profit:
            max_profit = profit
            max_count = 1
        elif max_profit == profit:
            max_count += 1
        max_a = max(max_a, A[i])
    
    print(max_count)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
