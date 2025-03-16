
# Define long long type alias for convenience
from sys import stdin, stdout
from collections import deque
from math import inf

# Constants for large values and mathematical constants
MOD = 1000000007

# Function to update the minimum value
def chmin(a, b):
    if a > b:
        a = b

# Function to update the maximum value
def chmax(a, b):
    if a < b:
        a = b

# Function to read input values
def read_list(t):
    return [t(x) for x in stdin.readline().split()]

# Function to read input values
def read_line(t):
    return t(stdin.readline())

# Function to read input values
def read_lines(t, N):
    return [t(stdin.readline()) for _ in range(N)]

# Function to read input values
def read_lines_str(N):
    return [stdin.readline().rstrip() for _ in range(N)]

# Function to read input values
def read_lines_int(N):
    return [int(x) for x in stdin.readline().split()]

# Function to read input values
def read_lines_int_str(N):
    return [int(x) for x in stdin.readline().split()]

# Function to read input values
def read_lines_float(N):
    return [float(x) for x in stdin.readline().split()]

# Function to read input values
def read_lines_float_str(N):
    return [float(x) for x in stdin.readline().split()]

# Function to read input values
def read_lines_str_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_str_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_int_float(N):
    return [int(x) for x in stdin.readline().split()]

# Function to read input values
def read_lines_int_float_str(N):
    return [int(x) for x in stdin.readline().split()]

# Function to read input values
def read_lines_float_int(N):
    return [float(x) for x in stdin.readline().split()]

# Function to read input values
def read_lines_float_int_str(N):
    return [float(x) for x in stdin.readline().split()]

# Function to read input values
def read_lines_int_str_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_int_str_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_int_str_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_int_str_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_float_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_float_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_float_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_float_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_float_float_int(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_float_float_int_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_float_float_float(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Function to read input values
def read_lines_float_str_float_str_float_float_float_float_float_float_float_float_float_float_str(N):
    return [stdin.readline().rstrip().split() for _ in range(N)]

# Fu