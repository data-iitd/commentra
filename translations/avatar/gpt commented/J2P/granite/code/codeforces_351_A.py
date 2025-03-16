
import sys

# Read the number of elements (n)
n = int(input())

# Read the input numbers and store them in a list
arr = list(map(float, input().split()))

# Variables to store the sums
sum_before = sum(arr)
sum_int = sum(int(x) for x in arr)

# Calculate the maximum possible sum considering non-integer values
max_sum = min(n, sum(1 for x in arr if x!= int(x))) + sum_int

# Calculate the minimum possible sum considering non-integer values
min_sum = max(0, sum(1 for x in arr if x!= int(x)) - n) + sum_int

# Determine the final answer based on the calculated sums
if min_sum > sum_before:
    ans = min_sum - sum_before
elif max_sum < sum_before:
    ans = sum_before - max_sum
else:
    # Case where the total sum is between min_sum and max_sum
    x = sum_before - sum_int
    ans = min(1 - x, x)

# Print the final answer formatted to three decimal places
print(f"{ans:.3f}")

