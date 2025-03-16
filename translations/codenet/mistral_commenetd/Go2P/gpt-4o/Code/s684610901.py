# Importing necessary packages
import sys
import math

# Define some constants
initial_buf_size = 10**4  # Initial buffer size
max_buf_size = 10**8       # Maximum buffer size
INF = 1e8                  # Infinite value for some calculations

# Initialize some global variables
di = [-1, 0, 1, 0]  # Direction vectors for 2D grid traversal
dj = [0, -1, 0, 1]  # Direction vectors for 2D grid traversal

# Main function
def main():
    # Read input A, B, and C
    A, B, C = map(int, input().split())

    # Check if C is within the range of A and B
    if A <= C <= B:
        print("Yes")  # Print "Yes" if condition is true
    else:
        print("No")   # Print "No" if condition is false

# Helper functions for reading input
def next_permutation(x):
    # Implementation of next permutation algorithm for sorting
    pass

def double_ary(h, w, init):
    # Function to initialize a 2D array with given dimensions and initial value
    return [[init] * w for _ in range(h)]

def ary_eq(a, b):
    # Function to check if two arrays are equal
    return a == b

def clone(n):
    # Function to clone a list
    return n[:]

def write(s):
    # Function to write a string to the output
    sys.stdout.write(s)

def print_flush():
    # Function to flush the output
    sys.stdout.flush()

def read_line():
    # Function to read a line from the input
    return input()

def read_int():
    # Function to read an integer from the input
    return int(input())

def read_float():
    # Function to read a float from the input
    return float(input())

def read_runes():
    # Function to read a list of runes (characters) from the input
    return list(input())

def read_string():
    # Function to read a string from the input
    return input()

def read_strings():
    # Function to read a list of strings from the input
    return input().split()

def s2i(s):
    # Function to convert a string to an integer
    return int(s)

def i2s(i):
    # Function to convert an integer to a string
    return str(i)

def abs_val(i):
    # Function to get the absolute value of an integer
    return abs(i)

def max_val(*args):
    # Function to get the maximum value from a list of integers
    return max(args)

def min_val(*args):
    # Function to get the minimum value from a list of integers
    return min(args)

def sum_vals(i):
    # Function to get the sum of elements in a list of integers
    return sum(i)

def split(s):
    # Function to split a string into a list of strings using space as delimiter
    return s.split()

def str_ary2int_ary(strs):
    # Function to convert a list of strings to a list of integers
    return list(map(int, strs))

def int_ary2str_ary(nums):
    # Function to convert a list of integers to a list of strings
    return list(map(str, nums))

def ary2str(strs):
    # Function to join a list of strings into a single string using space as delimiter
    return ' '.join(strs)

def reverse(res):
    # Function to reverse the order of elements in a list
    return res[::-1]

def reverse_str(res):
    # Function to reverse the order of elements in a list of strings
    return res[::-1]

def ini(res, init):
    # Function to initialize the first element of a list with a given value
    res[0] = init

# Entry point
if __name__ == "__main__":
    main()

# <END-OF-CODE>
