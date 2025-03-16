# B - AtCoder Beginner Contest 111

# Import the bisect module, which contains the bisect_left function.
import bisect

# Read an integer N from the standard input.
N = int(input())

# Define a list arr containing 10 integers.
arr = [111, 222, 333, 444, 555, 666, 777, 888, 999]

# Use the bisect_left function to find the index ans_idx of the first element in arr that is greater than or equal to N.
ans_idx = bisect.bisect_left(arr, N)

# Print the element at index ans_idx in arr.
print(arr[ans_idx])
