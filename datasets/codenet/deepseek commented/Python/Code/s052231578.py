
# B - AtCoder Beginner Contest 111

import bisect

# Read an integer input N
N = int(input())

# Define an array `arr` with specific values
arr = [111, 222, 333, 444, 555, 666, 777, 888, 999]

# Use `bisect_left` to find the index where N would be inserted to keep the array sorted
ans_idx = bisect.bisect_left(arr, N)

# Print the value at the found index
print(arr[ans_idx])

