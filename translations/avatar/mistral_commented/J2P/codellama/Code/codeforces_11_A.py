
import sys

# Read the number of elements in the array and the difference d from the input
n, d = map(int, input().split())

# Create an integer array of size n to store the numbers
nums = list(map(int, input().split()))

# Initialize variables for calculating the result and the difference between two consecutive numbers
result = 0
a = 0

# Iterate through the array starting from the second element
for i in range(1, n):
    # Calculate the difference between the current and previous numbers
    a = nums[i - 1] - nums[i]

    # If the difference is positive, add the number of jumps to the result and update the current number in the array
    if a >= 0:
        result += a // d + 1
        nums[i] += (a // d + 1) * d

# Print the result to the console
print(result)

