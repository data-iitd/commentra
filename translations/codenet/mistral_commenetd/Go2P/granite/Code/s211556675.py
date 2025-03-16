

import sys
import math

# I/O
def nextStr():
    return input()

def nextInt():
    return int(nextStr())

def nextFloat():
    return float(nextStr())

def nextRuneSlice():
    return list(nextStr())

def nextIntSlice(n):
    return [nextInt() for _ in range(n)]

def nextFloatSlice(n):
    return [nextFloat() for _ in range(n)]

# Arithmetic
def max(*nums):
    return max(nums)

def min(*nums):
    return min(nums)

def abs(x):
    return abs(x)

def pow(x, y):
    return x ** y

# Sort
class Val:
    def __init__(self, id, num):
        self.id = id
        self.num = num

class ByNum(list):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def __lt__(self, other):
        return self.num < other.num

# Main function
def main():
    sc = ByNum() # Initialize a new ByNum object
    wtr = sys.stdout # Initialize sys.stdout as the output writer

    # Read input values
    A, B, C, K = nextInt(), nextInt(), nextInt(), nextInt()

    # Find the maximum value among A, B, and C
    ma = max(A, B, C)

    # Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
    rest = 0
    if ma == A:
        rest += B + C
    elif ma == B:
        rest += A + C
    else:
        rest += A + B

    # Calculate the final answer
    answer = pow(ma, K) + rest

    # Write the answer to the output
    print(answer)

# 


