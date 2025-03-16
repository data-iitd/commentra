# B - AtCoder Beginner Contest 111

# Import the bisect module for binary search operations
import bisect

# Read an integer input from the user
N = int(input())

# Define a sorted list of predefined values
arr = [111, 222, 333, 444, 555, 666, 777, 888, 999]

# Use bisect to find the index where N can be inserted to maintain sorted order
ans_idx = bisect.bisect_left(arr, N)

# Print the value from arr at the found index
print(arr[ans_idx])
