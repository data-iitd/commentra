import sys
import io
import os
import math

def solve():
    # Function to solve the problem
    n = get_int()  # Read the number of elements in the array
    as_ = get_int_list(n)  # Read the array elements

    # Initialize an array xs of size n
    xs = [0] * n
    # Iterate through the array as and assign the value xs[i]
    for i, a in enumerate(as_):
        xs[i] = a - i + 1  # Assign the value xs[i] = a - i + 1

    # Sort the array xs in ascending order
    xs.sort()

    # Assign the middle element of the sorted array xs to variable b
    b = xs[n // 2]
    # Initialize variable ans with 0
    ans = 0
    # Iterate through the array xs and calculate the absolute difference between each element and b
    for x in xs:
        ans += abs(x - b)  # Calculate the absolute difference and add it to ans

    # Print the answer
    print(ans)

def abs(n):
    # Function to calculate the absolute difference of a number
    return n if n >= 0 else -n

# -----------------------------------------

# Set the maximum buffer size to 100,000,000
max_buf_size = int(1e8)

def get_int():
    # Function to read an integer from standard input
    return int(sys.stdin.readline().strip())

def get_int_list(n):
    # Function to read an array of n integers from standard input
    return list(map(int, sys.stdin.readline().strip().split()))

def get_string():
    # Function to read a string from standard input
    return sys.stdin.readline().strip()

def get_runes():
    # Function to read a rune string from standard input
    return list(get_string())

# Main function
if __name__ == "__main__":
    solve()
