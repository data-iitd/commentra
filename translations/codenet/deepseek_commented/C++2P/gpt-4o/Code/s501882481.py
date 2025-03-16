# Import necessary modules
from collections import deque  # For queue data structure
from typing import List, Tuple  # For type hinting
import sys  # For standard input/output operations

# Define constants
MOD = 1000000007  # Define a constant modulo value
MAX = 1 << 29  # Define a maximum value

# Utility function to convert a string to a string representation
def to_string(s: str) -> str:
    return s

# Utility function to convert a pair to a string representation
def to_string_pair(p: Tuple) -> str:
    return f"{{{to_string(p[0])},{to_string(p[1])}}}"

# Utility function to convert a list to a string representation
def to_string_list(v: List) -> str:
    return "{" + ",".join(to_string(x) for x in v) + "}"

# Debug function to print debug information
def debug(*args):
    print(" ".join(map(to_string, args)), file=sys.stderr)

# Print function to print multiple items
def print_items(*args):
    print(" ".join(map(to_string, args)))

# Utility function to read a single item
def get():
    return

# Utility function to read multiple items
def get_multiple(*args):
    for arg in args:
        arg[0] = input()

# Utility function to read a list of items
def get_list(vec: List):
    for i in range(len(vec)):
        vec[i] = input()

# Main function to execute the program
def main():
    S = input().strip()
    if S == "Sunny":
        print_items("Cloudy")
    elif S == "Cloudy":
        print_items("Rainy")
    else:
        print_items("Sunny")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
