# Read two integers from input: n (number of elements) and k (number of smallest elements to sum)
n, k = map(int, input().split())

# Read a list of integers from input and store it in 'li'
li = list(map(int, input().split()))

# Sort the list of integers in ascending order
li.sort()

# Select the first k elements from the sorted list (the k smallest elements)
tmp = li[:k]

# Calculate and print the sum of the selected k smallest elements
print(sum(tmp))
