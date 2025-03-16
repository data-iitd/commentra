
import sys
import math

# Reads a single integer from stdin and returns it as an integer.
def read_int():
    return int(sys.stdin.readline().rstrip())

# Reads a single integer from stdin and returns it as a string.
def read_str():
    return sys.stdin.readline().rstrip()

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints():
    return [int(x) for x in sys.stdin.readline().rstrip().split()]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs():
    return sys.stdin.readline().rstrip().split()

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_line():
    return [int(x) for x in sys.stdin.readline().rstrip().split()]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_line():
    return sys.stdin.readline().rstrip().split()

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines(n):
    return [[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines(n):
    return [sys.stdin.readline().rstrip().split() for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_2d(n):
    return [[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_2d(n):
    return [[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_3d(n):
    return [[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_3d(n):
    return [[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_4d(n):
    return [[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_4d(n):
    return [[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_5d(n):
    return [[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_5d(n):
    return [[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_6d(n):
    return [[[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_6d(n):
    return [[[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_7d(n):
    return [[[[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_7d(n):
    return [[[[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_8d(n):
    return [[[[[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_8d(n):
    return [[[[[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_9d(n):
    return [[[[[[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_9d(n):
    return [[[[[[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_10d(n):
    return [[[[[[[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_10d(n):
    return [[[[[[[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_11d(n):
    return [[[[[[[[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_11d(n):
    return [[[[[[[[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_12d(n):
    return [[[[[[[[[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_12d(n):
    return [[[[[[[[[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_13d(n):
    return [[[[[[[[[[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_13d(n):
    return [[[[[[[[[[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_14d(n):
    return [[[[[[[[[[[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_14d(n):
    return [[[[[[[[[[[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of integers.
def read_ints_lines_15d(n):
    return [[[[[[[[[[[[[[[int(x) for x in sys.stdin.readline().rstrip().split()] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)]

# Reads a single integer from stdin and returns it as a list of strings.
def read_strs_lines_15d(n):
    return [[[[[[[[[[[[[[[sys.stdin.readline().rstrip().split() for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(n)] for _ in range(