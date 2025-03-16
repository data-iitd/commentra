from statistics import median  # Importing median function from statistics module
from fractions import gcd  # Importing gcd function from fractions module
from itertools import combinations  # Importing combinations function from itertools module
from collections import deque  # Importing deque class from collections module
from collections import defaultdict  # Importing defaultdict class from collections module
import bisect  # Importing bisect module for maintaining sorted lists
import sys  # Importing sys module for system-specific parameters and functions

# Setting the maximum recursion limit to handle deep recursion cases
sys.setrecursionlimit(10000000)

# Defining a constant for modulo operation
mod = 10 ** 9 + 7

# Function to read a list of integers from input
def readInts():
    return list(map(int, input().split()))

# Main function to execute the logic
def main():
    n = int(input())  # Reading an integer input for 'n'
    A = readInts()  # Reading a list of integers
    A = sorted(A)  # Sorting the list of integers in ascending order
    ans = 0  # Initializing the answer variable to accumulate the result
    
    # Looping through the last 2*n elements of the sorted list in reverse order
    for i in range(len(A) - 2, len(A) - 2 * n - 1, -2):
        ans += A[i]  # Adding the current element to the answer
    
    print(ans)  # Printing the final accumulated answer

# Entry point of the program
if __name__ == '__main__':
    main()  # Calling the main function to execute the program
