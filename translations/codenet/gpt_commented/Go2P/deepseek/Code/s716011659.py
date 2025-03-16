import sys

# Read the number of elements in the array
n = int(input().strip())

# Read the input values into the array
arrA = list(map(int, input().strip().split()))

# Create a cumulative sum array to store the cumulative sums of arrA
cumSumA = [0] * (n + 1)
# Calculate the cumulative sums
for i in range(n):
    cumSumA[i + 1] = cumSumA[i] + arrA[i]

# Initialize the answer variable to a large value
ans = float('inf')
# Iterate through the cumulative sums to find the minimum difference
for i in range(1, n):
    # Calculate the absolute difference between the total sum and twice the current cumulative sum
    if abs(cumSumA[n] - (cumSumA[i] * 2)) < ans:
        # Update the answer if the current difference is smaller
        ans = abs(cumSumA[n] - cumSumA[i] * 2)

# Print the final answer as an integer
print(int(ans))
