
import sys

# Function to convert a number from base 10 to base N
def ten_to_n(number, n):
    s = "" # String to hold the result
    tmp = number # Temporary variable to hold the current number
    while True:
        # Prepend the remainder of the division to the result string
        s = str(tmp % n) + s
        if tmp < n: # If the temporary number is less than the base, exit the loop
            break
        tmp //= n # Divide the temporary number by the base
    return s # Return the converted string

# Function to read a line of input
def read_line():
    return sys.stdin.readline().strip()

# Function to read an integer from input
def read_int():
    return int(read_line())

# Function to read a float from input
def read_float():
    return float(read_line())

# Function to read runes from input
def read_runes():
    return list(read_line())

# Function to read a string from input
def read_string():
    return read_line()

# Function to read a slice of strings from input
def read_strings():
    return read_line().split()

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
def str_ary2int_ary(strs):
    return [int(s) for s in strs]

# Function to convert a slice of integers to a slice of strings
def int_ary2str_ary(nums):
    return [str(n) for n in nums]

# Function to join a slice of strings into a single string
def ary2str(strs):
    return " ".join(strs)

# Function to reverse a slice of integers
def reverse(res):
    return res[::-1]

# Function to initialize a slice with a given value
def initialize(res, init):
    if len(res) == 0:
        return
    res[0] = init
    for i in range(len(res)):
        res[i+1:] = res[:i]

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

# # Example function for stable sorting (commented out)
# def stable_sort_example():
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

# Main function
def main():
    # Read two integers N and K from input
    N, K = read_int(), read_int()
    # Convert the number N from base 10 to base K
    s = ten_to_n(N, K)
    # Print the length of the resulting string
    print(len(s))

if __name__ == "__main__":
    main()

