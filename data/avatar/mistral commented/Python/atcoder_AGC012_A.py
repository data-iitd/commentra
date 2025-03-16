#######
# Import necessary libraries
#######

from statistics import median  # For calculating median
from fractions import gcd  # For finding the greatest common divisor
from itertools import combinations  # For finding all combinations of a given length
from collections import deque  # For implementing a double ended queue
from collections import defaultdict  # For creating a dictionary with default values
import bisect  # For binary search
import sys
sys.setrecursionlimit(10000000)  # Setting the maximum recursion limit
mod = 10 ** 9 + 7  # Defining the modulus

#######
# Function to read integers from the standard input
#######

def readInts():
    """
    Reads a list of integers from the standard input.
    """
    return list(map(int, input().split()))

#######
# Main function
#######

def main():
    """
    Reads the number of integers 'n' and a list 'A' of 'n' integers from the standard input.
    Sorts the list 'A' in ascending order.
    Calculates the answer by summing up the elements of 'A' at indices which are not multiples of '2n+1'.
    Prints the answer.
    """
    n = int(input())
    A = readInts()
    A = sorted(A)
    ans = 0
    for i in range(len(A) - 2, len(A) - 2 * n - 1, -2):
        ans += A[i]
    print(ans)

#######
# Run the main function if the script is run as the main module
#######

if __name__ == '__main__':
    main()
