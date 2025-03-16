
# Package main is the entry point of the program
import sys

# Define a custom type 'pair' for sorting
class pair:
    def __init__(self, index, p1, p2):
        self.index = index
        self.p1 = p1
        self.p2 = p2

# Define a slice type 'pairs' for sorting 'pair' type
class pairs(list):
    def __init__(self, *args):
        super().__init__(*args)

    def __lt__(self, other):
        return self.index < other.index

    def __eq__(self, other):
        return self.index == other.index

# Define a custom type 'Int64Slice' for sorting int64 slices
class Int64Slice(list):
    def __init__(self, *args):
        super().__init__(*args)

    def __lt__(self, other):
        return self.index < other.index

    def __eq__(self, other):
        return self.index == other.index

# Define some constants
initialBufSize = 1e4 # Initial buffer size for bufio.NewScanner
maxBufSize = 1e8 # Maximum buffer size for bufio.NewScanner
INF = 1e8 # Infinite value for some calculations

# Initialize some global variables
scanner = sys.stdin # Input scanner
writer = sys.stdout # Output writer
di = [-1, 0, 1, 0] # Direction vectors for 2D grid traversal
dj = [0, -1, 0, 1] # Direction vectors for 2D grid traversal

# Main function
def main():
    # Initialize the buffer with the given size
    buf = make([]byte, initialBufSize)
    scanner.Buffer(buf, maxBufSize)
    scanner.Split(bufio.ScanWords) # Split input by words

    # Read input A, B, and C
    A, B, C = readInt(), readInt(), readInt()

    # Check if C is within the range of A and B
    if C >= A and C <= B:
        print("Yes") # Print "Yes" if condition is true
    else:
        print("No") # Print "No" if condition is false

# Helper functions for reading input
def NextPermutation(x):
    # Implementation of next permutation algorithm for sorting

def doubleAry(h, w, init):
    # Function to initialize a 2D int64 array with given dimensions and initial value

def aryEq(a, b):
    # Function to check if two arrays are equal

def clone(n):
    # Function to clone a slice

def write(s):
    # Function to write a string to the output writer

def print():
    # Function to flush the output writer

def readLine():
    # Function to read a line from the input scanner

def readInt():
    # Function to read an integer from the input scanner

def readFloat():
    # Function to read a float from the input scanner

def readRunes():
    # Function to read a rune slice from the input scanner

def readString():
    # Function to read a string from the input scanner

def readStrings():
    # Function to read a string slice from the input scanner

def s2i(s):
    # Function to convert a string to an integer

def i2s(i):
    # Function to convert an integer to a string

def abs(i):
    # Function to get the absolute value of an integer

def max(a):
    # Function to get the maximum value from a slice of integers

def min(a):
    # Function to get the minimum value from a slice of integers

def sum(i):
    # Function to get the sum of elements in a slice of integers

def split(s):
    # Function to split a string into a slice of strings using space as delimiter

def strAry2intAry(strs):
    # Function to convert a slice of strings to a slice of integers

def intAry2strAry(nums):
    # Function to convert a slice of integers to a slice of strings

def ary2str(strs):
    # Function to join a slice of strings into a single string using space as delimiter

def reverse(res):
    # Function to reverse the order of elements in a slice

def reverseStr(res):
    # Function to reverse the order of elements in a slice of strings

def ini(res, init):
    # Function to initialize the first element of a slice with a given value

# Uncomment the following code if you want to use regexp package
# def regexpExample():
#     # Your code here!
#     var str = "13:20"
#     r = regexp.MustCompile(`(\d+):(\d+)`)
#     fmt.Println(r.FindStringSubmatch(str))

# Define a custom type 'Country' with gold, silver, and bronze fields
# class Country:
#     def __init__(self, gold, silver, blonze):
#         self.gold = gold
#         self.silver = silver
#         self.blonze = blonze

# Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
# def stableSortExample():
#     # Your code here!

