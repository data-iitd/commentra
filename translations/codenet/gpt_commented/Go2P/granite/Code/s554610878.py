
import sys
import math

# Constants for buffer sizes
initialBufSize = 10000
maxBufSize = 1000000

# Global variables for scanner and modulus
sc = None
mod = 100000007

def main():
    # Array representing the days of the week
    week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
    
    # Get the input day as a string
    s = getString()
    index = -1 # Initialize index to -1 to indicate not found

    # Search for the input day in the week array
    for i, day in enumerate(week):
        if s == day:
            index = i # Update index if the day is found
            break

    # Calculate and print the number of days until the next Sunday
    print(7 - index)

# Function to read an integer from input
def getInt():
    global sc
    sc.next() # Scan the next token
    return int(sc.next()) # Convert the scanned text to an integer

# Function to read a string from input
def getString():
    global sc
    sc.next() # Scan the next token
    return sc.next() # Return the scanned text as a string

# Function to compute the absolute value of an integer
def abs(a):
    return int(math.fabs(a)) # Use math.fabs to get the absolute value

# Function to compute p raised to the power of q
def pow(p, q):
    return int(math.pow(p, q)) # Use math.pow for exponentiation

# Function to find the minimum value among given integers
def min(*nums):
    if len(nums) == 0:
        raise Exception("function min() requires at least one argument.") # Raise an exception if no arguments are provided
    res = nums[0] # Initialize result with the first number
    for i in range(len(nums)):
        res = min(res, nums[i]) # Update result with the minimum value
    return res # Return the minimum value

# Function to find the maximum value among given integers
def max(*nums):
    if len(nums) == 0:
        raise Exception("function max() requires at least one argument.") # Raise an exception if no arguments are provided
    res = nums[0] # Initialize result with the first number
    for i in range(len(nums)):
        res = max(res, nums[i]) # Update result with the maximum value
    return res # Return the maximum value

# Function to check if a string exists in a slice of strings
def strSearch(a, b):
    return b in a # Return True if the string is found, False otherwise

# Function to print an array of integers
def printIntArray(array):
    print(array) # Print the array

# Function to calculate the modulus of x with respect to the defined mod
def calcMod(x):
    return x % mod # Return the result of x modulo mod

# Initialize the scanner
sc = bufio.Scanner(sys.stdin)
sc.use_list = False
sc.list = []

# Call the main function
main()

