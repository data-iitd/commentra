
# Read two integers `n` and `k` from the standard input, separated by a space
n, k = map(int, input().split())

# Create a list of integers from the standard input, each line containing `n` integers
numbers = list(map(int, input().split()))

# Sort the list in ascending order
sorted_numbers = sorted(numbers)

# Calculate the sum of the first `k` elements of the sorted list
result = sum(sorted_numbers[:k])

# Print the result
print(result)