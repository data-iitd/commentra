from statistics import median
from fractions import gcd
from itertools import combinations
from collections import deque
from collections import defaultdict
import bisect
import sys
sys.setrecursionlimit(10000000)  # Set recursion limit to prevent stack overflow
mod = 10 ** 9 + 7  # Define modulo constant

# Function to read integers from input
def readInts():
    return list(map(int, input().split()))

# Main function
def main():
    n = int(input())  # Read integer n
    A = readInts()  # Read list A
    A = sorted(A)  # Sort the list A
    ans = 0  # Initialize answer variable
    
    # Calculate the sum of every second element from the end
    for i in range(len(A) - 2, len(A) - 2 * n - 1, -2):
        ans += A[i]
    
    print(ans)  # Print the calculated sum

# Entry point
if __name__ == '__main__':
    main()
