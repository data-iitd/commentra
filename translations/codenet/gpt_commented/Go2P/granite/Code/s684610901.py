
import bufio
import math
import os
import sys
from typing import List

# Define a structure for sorting pairs
class Pair:
    def __init__(self, index: int, p1: int, p2: int):
        self.index = index
        self.p1 = p1
        self.p2 = p2

# Define a structure for sorting int slices
class IntSlice(list):
    def __lt__(self, other):
        return self < other

# Constants for buffer sizes and infinity value
initial_buf_size = 10000
max_buf_size = 100000
INF = 100000000

# Global variables for input/output handling and direction vectors
scanner = bufio.Scanner(os.stdin.buffer, initial_buf_size)
writer = bufio.BufferedWriter(sys.stdout.buffer, max_buf_size)
di = [-1, 0, 1, 0]  # Direction vectors for row movement
dj = [0, -1, 0, 1]  # Direction vectors for column movement

def main():
    # Set up the scanner buffer and read three integers A, B, C
    buf = os.read(0, initial_buf_size)
    scanner.buffer = buf
    scanner.buffer_size = max_buf_size
    scanner.bytes = len(buf)
    scanner.reset()
    A = scanner.nextInt()
    B = scanner.nextInt()
    C = scanner.nextInt()

    # Check if C is within the range [A, B] and print the result
    if C >= A and C <= B:
        print("Yes")
    else:
        print("No")

# NextPermutation generates the next lexicographical permutation of the given sort.Interface
def next_permutation(x: List[int]) -> bool:
    n = len(x) - 1
    if n < 1:
        return False
    j = n - 1
    # Find the rightmost ascent
    while j >= 0 and x[j] >= x[j + 1]:
        j -= 1
    if j < 0:
        return False
    l = n
    # Find the rightmost successor to the pivot
    while x[j] >= x[l]:
        l -= 1
    x[j], x[l] = x[l], x[j]
    # Reverse the suffix
    for k, l in zip(range(j + 1, l + 1), range(n, j, -1)):
        x[k], x[l] = x[l], x[k]
    return True

# doubleAry initializes a 2D slice with a given height, width, and initial value
def double_ary(h: int, w: int, init: int) -> List[List[int]]:
    res = [[init for _ in range(w)] for _ in range(h)]
    return res

# aryEq checks if two int slices are equal
def ary_eq(a: List[int], b: List[int]) -> bool:
    return a == b

# clone creates a copy of an int slice
def clone(n: List[int]) -> List[int]:
    return n[:]

# write writes a string to the output buffer
def write(s: str):
    writer.write(s.encode())

# print flushes the output buffer
def print():
    writer.flush()

# readLine reads a line from the input
def read_line() -> str:
    scanner.scan()
    return scanner.string()

# readInt reads an int from the input
def read_int() -> int:
    scanner.scan()
    return scanner.nextInt()

# readFloat reads a float from the input
def read_float() -> float:
    scanner.scan()
    return scanner.float()

# readRunes reads a string and returns its runes
def read_runes() -> List[str]:
    scanner.scan()
    return list(scanner.string())

# readString reads a string from the input
def read_string() -> str:
    scanner.scan()
    return scanner.string()

# readStrings reads a string and returns its characters as a slice of strings
def read_strings() -> List[str]:
    scanner.scan()
    return list(scanner.string())

# s2i converts a string to int
def s2i(s: str) -> int:
    return int(s)

# i2s converts an int to string
def i2s(i: int) -> str:
    return str(i)

# s2f converts a string to float
def s2f(s: str) -> float:
    return float(s)

# abs returns the absolute value of an int
def abs(i: int) -> int:
    return abs(i)

# max returns the maximum value from a variadic list of int
def max(*args: int) -> int:
    return max(args)

# min returns the minimum value from a variadic list of int
def min(*args: int) -> int:
    return min(args)

# sum calculates the sum of an int slice
def sum(i: List[int]) -> int:
    return sum(i)

# split splits a string into fields
def split(s: str) -> List[str]:
    return s.split()

# strAry2intAry converts a slice of strings to a slice of int
def str_ary2int_ary(strs: List[str]) -> List[int]:
    return [s2i(s) for s in strs]

# intAry2strAry converts a slice of int to a slice of string
def int_ary2str_ary(nums: List[int]) -> List[str]:
    return [i2s(num) for num in nums]

# ary2str joins a slice of strings into a single string
def ary2str(strs: List[str]) -> str:
    return " ".join(strs)

# reverse reverses an int slice
def reverse(res: List[int]) -> List[int]:
    return res[::-1]

# reverseStr reverses a string slice
def reverse_str(res: List[str]) -> List[str]:
    return res[::-1]

# ini initializes the first element of a slice with a given value
def ini(res: List[int], init: int):
    if len(res) == 0:
        return
    res[0] = init
    for i in range(len(res)):
        res[i:] = res[:i]

# Uncomment the following function to see a regex example
# def regexp_example():
#     # Your code here!
#     str = "13:20"
#     r = re.compile(r"(\d+):(\d+)")
#     print(r.findall(str))

# Uncomment the following struct and function to see a stable sort example
# class Country:
#     def __init__(self, gold: int, silver: int, blonde: int):
#         self.gold = gold
#         self.silver = silver
#         self.blonde = blonde

# # Example of stable sorting
# def stable_sort_example() -> List[Country]:
#     country = [
#         Country(gold=1, silver=2, blonde=3),
#         Country(gold=1, silver=2, blonde=3),
#         Country(gold=1, silver=3, blonde=2),
#         Country(gold=1, silver=3, blonde=3),
#     ]
#     country.sort(key=lambda x: x.blonde, reverse=True)
#     country.sort(key=lambda x: x.silver, reverse=True)
#     country.sort(key=lambda x: x.gold, reverse=True)
#     return country

# Uncomment the following function to see a binary search example
# def binary_search_example(nums []int, target int) int {
#     left, right := 0, len(nums)-1
#     for left < right {
#         mid := left + (right - left) / 2
#         if nums[mid] == target {
#             return mid
#         } else if nums[mid] < target {
#             left = mid + 1
#         } else {
#             right = mid
#         }
#     }
#     return -1
# }

# Uncomment the following function to see a quick sort example
// func quickSortExample(nums []int) {
//     if len(nums) <= 1 {
//         return
//     }
//     pivot := nums[len(nums)/2]
//     left := quickSortExample(nums[:pivot])
//     right := quickSortExample(nums[pivot+1:])
//     quickSortExample(nums[left:right+1])
//     quickSortExample(nums)
//     return nums
// }
//     quickSortExample(nums []int) {
//         if len(nums) <= 1 {
//             return
//         }
//         pivot := len(nums)/2
//         left := quickSortExample(nums[:pivot])
//         right := quickSortExample(nums[pivot+1:])
//         quickSortExample(nums[left:right+1])
//         quickSortExample(nums) {
//             return nums
//         }
//     }
//     quickSortExample(nums []int) {
//         if len(nums) <= 1 {
//             return
//         }
//         pivot := len(nums)/2
//         left := quickSortExample(nums[:pivot])
//         right := quickSortExample(nums[pivot+1:])
//         quickSortExample(nums[left:right+1])
//         quickSortExample(nums) {
//             return nums
//         }
//     }
//     quickSortExample(nums []int) {
//         if len(nums) <= 1 {
//             return
//         }
//         pivot := len(nums)/2
//         left := quickSortExample(nums[:pivot])
//         right := quickSortExample(nums[pivot+1:])
//         quickSortExample(nums[left:right+1])
//         quickSortExample(nums) {
//             return nums
//         }
//     }
//     quickSortExample(nums []int) {
//         if len(nums) <= 1 {
//             return
//         }
//         pivot := len(nums)/2
//         left := quickSortExample(nums[:pivot])
//         right := quickSortExample(nums[pivot+1:])
//         quickSortExample(nums[left:right+1])
//         quickSortExample(nums) {
//             return nums
//         }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//     }
//