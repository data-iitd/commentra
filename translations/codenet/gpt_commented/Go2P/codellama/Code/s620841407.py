
import sys
import math

# Function to read an integer from stdin
def read_int():
    return int(sys.stdin.readline().rstrip())

# Function to read an integer from stdin
def read_int_list():
    return list(map(int, sys.stdin.readline().rstrip().split()))

# Function to read a string from stdin
def read_string():
    return sys.stdin.readline().rstrip()

# Function to read a string from stdin
def read_string_list():
    return list(map(str, sys.stdin.readline().rstrip().split()))

# Function to read a float from stdin
def read_float():
    return float(sys.stdin.readline().rstrip())

# Function to read a float from stdin
def read_float_list():
    return list(map(float, sys.stdin.readline().rstrip().split()))

# Function to print an integer to stdout
def print_int(n):
    sys.stdout.write(str(n) + "\n")

# Function to print a string to stdout
def print_string(s):
    sys.stdout.write(s + "\n")

# Function to print a float to stdout
def print_float(f):
    sys.stdout.write(str(f) + "\n")

# Function to print a list of integers to stdout
def print_int_list(l):
    for i in l:
        print_int(i)

# Function to print a list of strings to stdout
def print_string_list(l):
    for s in l:
        print_string(s)

# Function to print a list of floats to stdout
def print_float_list(l):
    for f in l:
        print_float(f)

# Function to print a 2D list of integers to stdout
def print_int_matrix(m):
    for r in m:
        print_int_list(r)

# Function to print a 2D list of strings to stdout
def print_string_matrix(m):
    for r in m:
        print_string_list(r)

# Function to print a 2D list of floats to stdout
def print_float_matrix(m):
    for r in m:
        print_float_list(r)

# Function to print a list of lists of integers to stdout
def print_int_matrix_list(l):
    for r in l:
        print_int_list(r)

# Function to print a list of lists of strings to stdout
def print_string_matrix_list(l):
    for r in l:
        print_string_list(r)

# Function to print a list of lists of floats to stdout
def print_float_matrix_list(l):
    for r in l:
        print_float_list(r)

# Function to print a list of lists of lists of integers to stdout
def print_int_matrix_list_list(l):
    for r in l:
        print_int_matrix_list(r)

# Function to print a list of lists of lists of strings to stdout
def print_string_matrix_list_list(l):
    for r in l:
        print_string_matrix_list(r)

# Function to print a list of lists of lists of floats to stdout
def print_float_matrix_list_list(l):
    for r in l:
        print_float_matrix_list(r)

# Function to print a list of lists of lists of lists of integers to stdout
def print_int_matrix_list_list_list(l):
    for r in l:
        print_int_matrix_list_list(r)

# Function to print a list of lists of lists of lists of strings to stdout
def print_string_matrix_list_list_list(l):
    for r in l:
        print_string_matrix_list_list(r)

# Function to print a list of lists of lists of lists of floats to stdout
def print_float_matrix_list_list_list(l):
    for r in l:
        print_float_matrix_list_list(r)

# Function to print a list of lists of lists of lists of lists of integers to stdout
def print_int_matrix_list_list_list_list(l):
    for r in l:
        print_int_matrix_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of strings to stdout
def print_string_matrix_list_list_list_list(l):
    for r in l:
        print_string_matrix_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of floats to stdout
def print_float_matrix_list_list_list_list(l):
    for r in l:
        print_float_matrix_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of integers to stdout
def print_int_matrix_list_list_list_list_list(l):
    for r in l:
        print_int_matrix_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of strings to stdout
def print_string_matrix_list_list_list_list_list(l):
    for r in l:
        print_string_matrix_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of floats to stdout
def print_float_matrix_list_list_list_list_list(l):
    for r in l:
        print_float_matrix_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of integers to stdout
def print_int_matrix_list_list_list_list_list_list(l):
    for r in l:
        print_int_matrix_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of strings to stdout
def print_string_matrix_list_list_list_list_list_list(l):
    for r in l:
        print_string_matrix_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of floats to stdout
def print_float_matrix_list_list_list_list_list_list(l):
    for r in l:
        print_float_matrix_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of integers to stdout
def print_int_matrix_list_list_list_list_list_list_list(l):
    for r in l:
        print_int_matrix_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of strings to stdout
def print_string_matrix_list_list_list_list_list_list_list(l):
    for r in l:
        print_string_matrix_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of floats to stdout
def print_float_matrix_list_list_list_list_list_list_list(l):
    for r in l:
        print_float_matrix_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of integers to stdout
def print_int_matrix_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_int_matrix_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of strings to stdout
def print_string_matrix_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_string_matrix_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of floats to stdout
def print_float_matrix_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_float_matrix_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of integers to stdout
def print_int_matrix_list_list_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_int_matrix_list_list_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of strings to stdout
def print_string_matrix_list_list_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_string_matrix_list_list_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of floats to stdout
def print_float_matrix_list_list_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_float_matrix_list_list_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of integers to stdout
def print_int_matrix_list_list_list_list_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_int_matrix_list_list_list_list_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of strings to stdout
def print_string_matrix_list_list_list_list_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_string_matrix_list_list_list_list_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of floats to stdout
def print_float_matrix_list_list_list_list_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_float_matrix_list_list_list_list_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of integers to stdout
def print_int_matrix_list_list_list_list_list_list_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_int_matrix_list_list_list_list_list_list_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of strings to stdout
def print_string_matrix_list_list_list_list_list_list_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_string_matrix_list_list_list_list_list_list_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of floats to stdout
def print_float_matrix_list_list_list_list_list_list_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_float_matrix_list_list_list_list_list_list_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of integers to stdout
def print_int_matrix_list_list_list_list_list_list_list_list_list_list_list_list_list_list_list_list(l):
    for r in l:
        print_int_matrix_list_list_list_list_list_list_list_list_list_list_list_list_list_list_list(r)

# Function to print a list of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists of lists o