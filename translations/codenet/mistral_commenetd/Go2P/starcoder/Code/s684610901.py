# Package main is the entry point of the program
import math
import os
import random
import re
import sys

# Define a custom type 'pair' for sorting
class pair:
    def __init__(self, index, p1, p2):
        self.index = index
        self.p1 = p1
        self.p2 = p2

# Define a slice type 'pairs' for sorting 'pair' type
class pairs(list):
    def __init__(self, pairs):
        self.extend(pairs)

    def __lt__(self, other):
        return self[0].index < other[0].index

# Define a custom type 'Int64Slice' for sorting int64 slices
class Int64Slice(list):
    def __init__(self, int64s):
        self.extend(int64s)

    def __lt__(self, other):
        return self[0] < other[0]

# Define some constants
INF = 1e8

# Initialize some global variables
di = [-1, 0, 1, 0]
dj = [0, -1, 0, 1]

# Main function
def main():
    # Read input A, B, and C
    A, B, C = read_int(), read_int(), read_int()

    # Check if C is within the range of A and B
    if C >= A and C <= B:
        print("Yes") # Print "Yes" if condition is true
    else:
        print("No")  # Print "No" if condition is false

# Helper functions for reading input
def read_int():
    # Function to read an integer from the input scanner
    return int(input())

def read_float():
    # Function to read a float from the input scanner
    return float(input())

def read_string():
    # Function to read a string from the input scanner
    return input()

def read_strings():
    # Function to read a string slice from the input scanner
    return input().split()

def read_ints():
    # Function to read a string slice from the input scanner
    return list(map(int, input().split()))

def read_floats():
    # Function to read a string slice from the input scanner
    return list(map(float, input().split()))

def read_runes():
    # Function to read a rune slice from the input scanner
    return list(input())

def s2i(s):
    # Function to convert a string to an integer
    return int(s)

def i2s(i):
    # Function to convert an integer to a string
    return str(i)

def abs(i):
    # Function to get the absolute value of an integer
    return abs(i)

def max(a, b):
    # Function to get the maximum value from a slice of integers
    return max(a, b)

def min(a, b):
    # Function to get the minimum value from a slice of integers
    return min(a, b)

def sum(i):
    # Function to get the sum of elements in a slice of integers
    return sum(i)

def split(s):
    # Function to split a string into a slice of strings using space as delimiter
    return s.split()

def strAry2intAry(strs):
    # Function to convert a slice of strings to a slice of integers
    return list(map(int, strs))

def intAry2strAry(nums):
    # Function to convert a slice of integers to a slice of strings
    return list(map(str, nums))

def ary2str(strs):
    # Function to join a slice of strings into a single string using space as delimiter
    return''.join(strs)

def reverse(res):
    # Function to reverse the order of elements in a slice
    return res[::-1]

def reverseStr(res):
    # Function to reverse the order of elements in a slice of strings
    return res[::-1]

def ini(res, init):
    # Function to initialize the first element of a slice with a given value
    res[0] = init

# Define a custom type 'Country' with gold, silver, and bronze fields
# class Country:
#     def __init__(self, gold, silver, bronze):
#         self.gold = gold
#         self.silver = silver
#         self.bronze = bronze

# Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
# def stableSortExample():
#     # Your code here!
#     return []

# Uncomment the following code if you want to use regexp package
# def regexpExample():
#     # Your code here!
#     str = "13:20"
#     r = re.compile(r"(\d+):(\d+)")
#     print(r.findall(str))

# Translate the above Python code to C++ and end with comment "