
import sys
import math

# Global variables
mod = 1000000007

# Main function to determine the number of days until Sunday for a given day.
def main():
    week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
    s = input() # Get the input day as a string.
    index = -1
    for i, day in enumerate(week):
        if s == day:
            index = i # Set the index of the day found in the week array.
            break
    print(7 - index) # Print the number of days until Sunday.

# Helper function to read an integer from standard input.
def getInt():
    return int(sys.stdin.readline())

# Helper function to read a string from standard input.
def getString():
    return sys.stdin.readline().strip()

# Function to return the absolute value of an integer.
def abs(a):
    return int(math.fabs(a))

# Function to return the result of raising the first argument to the power of the second argument.
def pow(p, q):
    return int(math.pow(p, q))

# Function to return the smallest integer from a list of integers.
def min(*nums):
    if len(nums) == 0:
        raise ValueError("function min() requires at least one argument.")
    res = nums[0]
    for num in nums:
        res = min(res, num)
    return res

# Function to return the largest integer from a list of integers.
def max(*nums):
    if len(nums) == 0:
        raise ValueError("function max() requires at least one argument.")
    res = nums[0]
    for num in nums:
        res = max(res, num)
    return res

# Function to check if a string is present in a slice of strings.
def strSearch(a, b):
    return b in a

# Function to print a slice of integers in a specific format.
def printIntArray(array):
    print("[{}]".format(", ".join(map(str, array))))

# Function to return the modulo of an integer with respect to mod.
def calcMod(x):
    return x % mod

# End of code

