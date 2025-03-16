import sys
import math
from typing import List, Tuple

# Constants for infinity value
INF = 1e8

def main():
    # Read three integers A, B, C
    A, B, C = map(int, sys.stdin.readline().split())
    
    # Check if C is within the range [A, B] and print the result
    if A <= C <= B:
        print("Yes")
    else:
        print("No")

# Utility functions

def next_permutation(arr: List[int]) -> bool:
    n = len(arr) - 1
    if n < 1:
        return False
    j = n - 1
    # Find the rightmost ascent
    while j >= 0 and arr[j] >= arr[j + 1]:
        j -= 1
    if j < 0:
        return False
    l = n
    # Find the rightmost successor to the pivot
    while arr[j] >= arr[l]:
        l -= 1
    arr[j], arr[l] = arr[l], arr[j]  # Swap the pivot with its successor
    # Reverse the suffix
    arr[j + 1:] = reversed(arr[j + 1:])
    return True

def double_ary(h: int, w: int, init: int) -> List[List[int]]:
    return [[init] * w for _ in range(h)]

def ary_eq(a: List[int], b: List[int]) -> bool:
    return a == b

def clone(n: List[int]) -> List[int]:
    return n.copy()

def write(s: str):
    sys.stdout.write(s)

def print_flush():
    sys.stdout.flush()

def read_line() -> str:
    return sys.stdin.readline().strip()

def read_int() -> int:
    return int(sys.stdin.readline().strip())

def read_float() -> float:
    return float(sys.stdin.readline().strip())

def read_runes() -> List[str]:
    return list(sys.stdin.readline().strip())

def read_string() -> str:
    return sys.stdin.readline().strip()

def read_strings() -> List[str]:
    return list(sys.stdin.readline().strip())

def s2i(s: str) -> int:
    return int(s)

def i2s(i: int) -> str:
    return str(i)

def s2f(s: str) -> float:
    return float(s)

def abs_val(i: int) -> int:
    return abs(i)

def max_val(*args: int) -> int:
    return max(args)

def min_val(*args: int) -> int:
    return min(args)

def sum_vals(i: List[int]) -> int:
    return sum(i)

def split(s: str) -> List[str]:
    return s.split()

def str_ary_to_int_ary(strs: List[str]) -> List[int]:
    return [s2i(str_val) for str_val in strs]

def int_ary_to_str_ary(nums: List[int]) -> List[str]:
    return [i2s(num) for num in nums]

def ary_to_str(strs: List[str]) -> str:
    return ' '.join(strs)

def reverse(res: List[int]) -> List[int]:
    return res[::-1]

def reverse_str(res: List[str]) -> List[str]:
    return res[::-1]

def ini(res: List[int], init: int):
    if len(res) == 0:
        return
    res[0] = init
    for i in range(len(res)):
        res[i:] = res[:i]

# Uncomment the following function to see a regex example
# import re
# def regexp_example():
#     str_val = "13:20"
#     pattern = re.compile(r'(\d+):(\d+)')
#     print(pattern.findall(str_val))

# Uncomment the following class and function to see a stable sort example
# class Country:
#     def __init__(self, gold: int, silver: int, bronze: int):
#         self.gold = gold
#         self.silver = silver
#         self.bronze = bronze

# def stable_sort_example() -> List[Country]:
#     countries = [
#         Country(1, 2, 3),
#         Country(1, 2, 3),
#         Country(1, 3, 2),
#         Country(1, 3, 3),
#     ]
#     countries.sort(key=lambda c: c.bronze, reverse=True)
#     countries.sort(key=lambda c: c.silver, reverse=True)
#     countries.sort(key=lambda c: c.gold, reverse=True)
#     return countries

if __name__ == "__main__":
    main()

# <END-OF-CODE>
