
import sys

# Reading the number of elements in the array
n = int(input())

# Initializing an array to hold the input values
arr = list(map(int, input().split()))

# Initialize the answer with the absolute value of the first element
answer = abs(arr[0])

# Loop to calculate the sum of absolute differences between consecutive elements
for i in range(1, n):
    answer += abs(arr[i] - arr[i - 1])

# Output the final calculated answer
print(answer)

