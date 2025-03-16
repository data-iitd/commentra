
import bufio
import os
import sys

# Constants for buffer sizes
INITIAL_BUF_SIZE = 10000
MAX_BUF_SIZE = 100000

# Global variables for input and output
scanner = bufio.Scanner(os.Stdin, INITIAL_BUF_SIZE, MAX_BUF_SIZE)
writer = bufio.BufferedWriter(sys.stdout)

def main():
    # Read two integers N and K from input
    N = int(scanner.next())
    K = int(scanner.next())
    # Convert the number N from base 10 to base K
    s = ten_to_n(N, K)
    # Print the length of the resulting string
    print(len(s))

def ten_to_n(number, n):
    s = ""
    tmp = number
    while tmp > 0:
        # Prepend the remainder of the division to the result string
        s = str(tmp % n) + s
        if tmp < n:
            break
        tmp //= n
    return s

# Write a string to the output
def write(s):
    writer.write(s)

# Flush the writer buffer to output
def print():
    writer.flush()

# Read a line of input
def read_line():
    return scanner.next()

# Read an integer from input
def read_int():
    return int(scanner.next())

# Read a float from input
def read_float():
    return float(scanner.next())

# Read runes from input
def read_runes():
    return [ord(c) for c in scanner.next()]

# Read a string from input
def read_string():
    return scanner.next()

# Read a slice of strings from input
def read_strings():
    return scanner.next().split()

# Convert a string to an integer
def s2i(s):
    return int(s)

# Convert an integer to a string
def i2s(i):
    return str(i)

# Convert a string to a float
def s2f(s):
    return float(s)

# Calculate the sum of a slice of integers
def sum(i):
    return sum(i)

# Split a string into a slice of strings
def split(s):
    return s.split()

# Convert a slice of strings to a slice of integers
def str_ary2int_ary(strs):
    return [s2i(s) for s in strs]

# Convert a slice of integers to a slice of strings
def int_ary2str_ary(nums):
    return [i2s(num) for num in nums]

# Join a slice of strings into a single string
def ary2str(strs):
    return " ".join(strs)

# Reverse a slice of integers
def reverse(res):
    return res[::-1]

# Initialize a slice with a given value
def initialize(res, init):
    if len(res) == 0:
        return
    res[0] = init
    for i in range(len(res)):
        res[i] = res[0]

# Example function for regular expressions (commented out)
# def regexp_example():
#     # Your code here!
#     str = "13:20"
#     r = re.compile(r"(\d+):(\d+)")
#     print(r.findall(str))

# Struct to hold medal counts for a country (commented out)
# class Country:
#     def __init__(self, gold, silver, blonze):
#         self.gold = gold
#         self.silver = silver
#         self.blonze = blonze

# Example function for stable sorting (commented out)
# def stable_sort_example():
#     country = [
#         Country(1, 2, 3),
#         Country(1, 2, 3),
#         Country(1, 3, 2),
#         Country(1, 3, 3),
#     ]
#     country.sort(key=lambda c: c.blonze, reverse=True)
#     country.sort(key=lambda c: c.silver, reverse=True)
#     country.sort(key=lambda c: c.gold, reverse=True)
#     return country

# Example usage of the functions
if __name__ == "__main__":
    main()

