
n, k = map(int, input().split())  # Read the first two integers from the input and convert them to integers
li = []                           # Create an empty list to store the integers we will read from the input

# Read the integers from the input and add them to the list li
li = list(map(int, input().split()))

# Sort the list li in ascending order
li.sort()

# Create a new list tmp by slicing the first k elements from the sorted list li
tmp = li[:k]

# Calculate the sum of the elements in the list tmp
sum_tmp = sum(tmp)

# Print the sum of the first k integers
print(sum_tmp)