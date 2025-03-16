
import sys

def min(nums):
    min = nums[0]
    for v in nums:
        if v < min:
            min = v
    return min

n, a, b = map(int, sys.stdin.readline().split())
print(min([n*a, b]))

