
# Read the number of elements (n) and the number of smallest elements to sum (k)
n, k = map(int, input().split())

# Read n integers into the array p
p = list(map(int, input().split()))

# Selection sort algorithm to sort the array p in ascending order
for i in range(n):
    l = i # Assume the minimum is the first element
    for j in range(i + 1, n):
        # Update l if a smaller element is found
        if p[j] < p[l]:
            l = j
    # Swap the found minimum element with the first element
    if l!= i:
        p[i], p[l] = p[l], p[i]

# Calculate the sum of the first k smallest elements in the sorted array
o = sum(p[:k])

# Print the result: the sum of the k smallest elements
print(o)

