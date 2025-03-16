# Python 3

# Constants for buffer sizes
INITIAL_BUF_SIZE = 1e4 # Initial buffer size for scanner
MAX_BUF_SIZE = 1e8 # Maximum buffer size for scanner

# Global variables for input and output
scanner = __import__('sys').stdin # Scanner for reading input
writer = __import__('sys').stdout # Writer for output

def main():
    # Allocate buffer for scanner and set its maximum size
    buf = __import__('array').array('b', [0] * INITIAL_BUF_SIZE)
    scanner.buffer = buf.buffer
    scanner.bufsize = buf.buffer_info()[1]
    scanner.maxbuf = MAX_BUF_SIZE
    scanner.split(lambda x: x.split()) # Set scanner to split input by words

    # Read two integers N and K from input
    N, K = readInt(), readInt()
    # Convert the number N from base 10 to base K
    s = TenToN(N, K)
    # Print the length of the resulting string
    print(len(s))

# Function to convert a number from base 10 to base N
def TenToN(number, n):
    s = '' # String to hold the result
    tmp = number # Temporary variable to hold the current number
    while True:
        # Prepend the remainder of the division to the result string
        s = i2s(tmp%n) + s
        if tmp < n: # If the temporary number is less than the base, exit the loop
            break
        tmp //= n # Divide the temporary number by the base
    return s # Return the converted string

# Function to write a string to the output
def write(s):
    writer.write(s)

# Function to flush the writer buffer to output
def print():
    writer.flush()

# Function to read a line of input
def readLine():
    return scanner.readline().rstrip()

# Function to read an integer from input
def readInt():
    return int(scanner.readline().rstrip())

# Function to read a float from input
def readFloat():
    return float(scanner.readline().rstrip())

# Function to read runes from input
def readRunes():
    return list(map(lambda x: ord(x), scanner.readline().rstrip()))

# Function to read a string from input
def readString():
    return str(scanner.readline().rstrip())

# Function to read a slice of strings from input
def readStrings():
    return list(map(str, scanner.readline().rstrip().split()))

# Function to convert a string to an integer
def s2i(s):
    return int(s)

# Function to convert an integer to a string
def i2s(i):
    return str(i)

# Function to convert a string to a float
def s2f(s):
    return float(s)

# Function to calculate the sum of a slice of integers
def sum(i):
    return sum(i)

# Function to split a string into a slice of strings
def split(s):
    return s.split()

# Function to convert a slice of strings to a slice of integers
def strAry2intAry(strs):
    return list(map(int, strs))

# Function to convert a slice of integers to a slice of strings
def intAry2strAry(nums):
    return list(map(str, nums))

# Function to join a slice of strings into a single string
def ary2str(strs):
    return''.join(strs)

# Function to reverse a slice of integers
def reverse(res):
    return res[::-1]

# Function to initialize a slice with a given value
def initalize(res, init):
    if len(res) == 0:
        return # Do nothing if the slice is empty
    res[0] = init # Set the first element to the initial value
    for i in range(len(res)):
        res[i:] = res[:i] # Copy elements to shift them

# Example function for regular expressions (commented out)
# def regexpExample():
#     # Your code here!
#     str = "13:20"
#     r = __import__('re').compile(r"(\d+):(\d+)")
#     print(r.findall(str))

# Struct to hold medal counts for a country (commented out)
# class Country:
#     def __init__(self, gold, silver, blonze):
#         self.gold = gold
#         self.silver = silver
#         self.blonze = blonze

# # Example function for stable sorting (commented out)
# def stableSortExample():
#     country = [
#         Country(1, 2, 3),
#         Country(1, 2, 3),
#         Country(1, 3, 2),
#         Country(1, 3, 3),
#     ]
#     country.sort(key=lambda x: x.blonze, reverse=True)
#     country.sort(key=lambda x: x.silver, reverse=True)
#     country.sort(key=lambda x: x.gold, reverse=True)
#     return country

