import sys
import math

def next_int():
    return int(sys.stdin.readline().strip())

def scan_nums(length):
    nums = list(map(int, sys.stdin.readline().strip().split()))
    return nums

def pattern1(l):
    return (l[0] * l[3]) + (l[1] * l[4])

def pattern2(l):
    return 2 * l[2] * max(l[3], l[4])

def pattern3(l):
    return 2 * l[2] * min(l[3], l[4]) + doch(l)

def min_value(*nums):
    if len(nums) == 0:
        raise ValueError("Function min_value() requires at least one argument.")
    return min(nums)

def max_value(*nums):
    if len(nums) == 0:
        raise ValueError("Function max_value() requires at least one argument.")
    return max(nums)

def doch(l):
    if l[3] > l[4]:
        return l[0] * (l[3] - l[4])
    else:
        return l[1] * (l[4] - l[3])

def main():
    length = 5
    l = scan_nums(length)
    print(min_value(pattern1(l), pattern2(l), pattern3(l)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
