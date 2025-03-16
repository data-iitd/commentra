import sys
import math
from typing import List, Tuple

# Constants
INF = 1e8

# Function to read integers from input
def read_int() -> int:
    return int(sys.stdin.readline().strip())

# Function to check if C lies between A and B
def main():
    A = read_int()
    B = read_int()
    C = read_int()
    
    if A <= C <= B:
        print("Yes")
    else:
        print("No")

# Entry point of the program
if __name__ == "__main__":
    main()

# Utility functions

# Function to find the next permutation of a list
def next_permutation(x: List[int]) -> bool:
    n = len(x) - 1
    if n < 1:
        return False
    j = n - 1
    while j >= 0 and x[j] >= x[j + 1]:
        j -= 1
    if j < 0:
        return False
    l = n
    while x[j] >= x[l]:
        l -= 1
    x[j], x[l] = x[l], x[j]
    x[j + 1:] = reversed(x[j + 1:])
    return True

# Function to create a 2D list initialized with a given value
def double_ary(h: int, w: int, init: int) -> List[List[int]]:
    return [[init] * w for _ in range(h)]

# Function to check if two lists are equal
def ary_eq(a: List[int], b: List[int]) -> bool:
    return a == b

# Function to clone a list
def clone(n: List[int]) -> List[int]:
    return n.copy()

# Function to write a string to output
def write(s: str):
    sys.stdout.write(s)

# Function to read a line of text from input
def read_line() -> str:
    return sys.stdin.readline().strip()

# Function to read a float from input
def read_float() -> float:
    return float(sys.stdin.readline().strip())

# Function to read a list of runes (characters)
def read_runes() -> List[str]:
    return list(sys.stdin.readline().strip())

# Function to read a string from input
def read_string() -> str:
    return sys.stdin.readline().strip()

# Function to read multiple strings from input
def read_strings() -> List[str]:
    return sys.stdin.readline().strip().split()

# Function to convert a string to an integer
def s2i(s: str) -> int:
    return int(s)

# Function to convert an integer to a string
def i2s(i: int) -> str:
    return str(i)

# Function to convert a string to a float
def s2f(s: str) -> float:
    return float(s)

# Function to return the absolute value of an integer
def abs_val(i: int) -> int:
    return abs(i)

# Function to return the maximum value in a list of integers
def max_val(*args: int) -> int:
    return max(args)

# Function to return the minimum value in a list of integers
def min_val(*args: int) -> int:
    return min(args)

# Function to return the sum of a list of integers
def sum_list(i: List[int]) -> int:
    return sum(i)

# Function to split a string into a list of strings
def split(s: str) -> List[str]:
    return s.split()

# Function to convert a list of strings to a list of integers
def str_ary_to_int_ary(strs: List[str]) -> List[int]:
    return [s2i(str_val) for str_val in strs]

# Function to convert a list of integers to a list of strings
def int_ary_to_str_ary(nums: List[int]) -> List[str]:
    return [i2s(num) for num in nums]

# Function to join a list of strings into a single string
def ary_to_str(strs: List[str]) -> str:
    return ' '.join(strs)

# Function to reverse a list of integers
def reverse(res: List[int]) -> List[int]:
    return res[::-1]

# Function to reverse a list of strings
def reverse_str(res: List[str]) -> List[str]:
    return res[::-1]

# Function to initialize a list with a specific value
def ini(res: List[int], init: int):
    if len(res) == 0:
        return
    res[0] = init
    for i in range(len(res)):
        res[i] = init

# <END-OF-CODE>
