# problem_b.py
# This is the main file for problem B solution

import sys
import math

constMod = int(1e9) + 7  # Constants definition

# Function definitions

def get_int():  # Function to read an integer from standard input
    return int(sys.stdin.readline().strip())

def get_int_slice(n):  # Function to read n integers and return a list
    return list(map(int, sys.stdin.readline().strip().split()))

def solve():  # Function to solve the problem
    n, m = get_int(), get_int()
    a = get_int_slice(n)

    total_sum = sum(a)

    count = sum(1 for v in a if v >= total_sum / (4 * m))

    if count >= m:
        print("Yes")
    else:
        print("No")

# Main function
if __name__ == "__main__":  # Main function
    solve()

# <END-OF-CODE>
