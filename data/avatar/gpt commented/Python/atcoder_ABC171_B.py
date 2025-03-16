# Read two integers n and k from input, where n is the total number of elements 
# and k is the number of smallest elements to sum.
n, k = map(int, input().split())

# Read a list of n integers from input, convert them to integers, and sort the list.
# Then, take the first k elements from the sorted list.
# Finally, calculate the sum of these k smallest elements.
print(sum(sorted(list(map(int, input().split())))[:k]))
