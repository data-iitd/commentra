import sys
import math

# Constants
initial_buf_size = 10**4
max_buf_size = 10**8
INF = 10**8

def read_int():
    return int(sys.stdin.readline().strip())

def main():
    A = read_int()
    B = read_int()
    C = read_int()
    
    if C >= A and C <= B:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# Utility functions
def next_permutation(x):
    n = len(x) - 1
    if n < 1:
        return False
    j = n - 1
    while j >= 0 and not x[j] < x[j + 1]:
        j -= 1
    if j < 0:
        return False
    l = n
    while not x[j] < x[l]:
        l -= 1
    x[j], x[l] = x[l], x[j]
    x[j + 1:] = reversed(x[j + 1:])
    return True

def double_array(h, w, init):
    return [[init] * w for _ in range(h)]

def array_equal(a, b):
    return a == b

def clone(n):
    return n[:]

def write(s):
    sys.stdout.write(s)

def flush():
    sys.stdout.flush()

def read_line():
    return sys.stdin.readline().strip()

def read_float():
    return float(sys.stdin.readline().strip())

def read_runes():
    return list(sys.stdin.readline().strip())

def read_string():
    return sys.stdin.readline().strip()

def read_strings():
    return list(sys.stdin.readline().strip())

def s2i(s):
    return int(s)

def i2s(i):
    return str(i)

def s2f(s):
    return float(s)

def abs_val(i):
    return abs(i)

def max_val(*args):
    return max(args)

def min_val(*args):
    return min(args)

def sum_array(i):
    return sum(i)

def split(s):
    return s.split()

def str_array_to_int_array(strs):
    return [s2i(s) for s in strs]

def int_array_to_str_array(nums):
    return [i2s(num) for num in nums]

def array_to_str(strs):
    return ' '.join(strs)

def reverse_array(res):
    return res[::-1]

def ini(res, init):
    if len(res) == 0:
        return
    res[0] = init
    for i in range(len(res)):
        res[i:] = res[:i]

# Example usage of regular expressions (commented out)
# import re
# def regexp_example():
#     str_val = "13:20"
#     pattern = re.compile(r'(\d+):(\d+)')
#     print(pattern.findall(str_val))

# Example of sorting a list of dictionaries (commented out)
# def stable_sort_example():
#     countries = [
#         {'gold': 1, 'silver': 2, 'bronze': 3},
#         {'gold': 1, 'silver': 2, 'bronze': 3},
#         {'gold': 1, 'silver': 3, 'bronze': 2},
#         {'gold': 1, 'silver': 3, 'bronze': 3},
#     ]
#     countries.sort(key=lambda x: x['bronze'], reverse=True)
#     countries.sort(key=lambda x: x['silver'], reverse=True)
#     countries.sort(key=lambda x: x['gold'], reverse=True)
#     return countries

# <END-OF-CODE>
