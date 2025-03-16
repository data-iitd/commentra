#<START-OF-CODE>

# Declare variables
n, k, p, i, j, l, m, o = 0, 0, [], 0, 0, 0, 0, 0, 0

# Read the number of elements (n) and the number of smallest elements to sum (k)
n, k = map(int, input().split())

# Read n integers into the array p
for i in range(n):
    p.append(int(input()))

# Selection sort algorithm to sort the array p in ascending order
for i in range(n):
    l = i # Assume the minimum is the first element
    for j in range(i + 1, n):
        # Update l if a smaller element is found
        if(p[j] < p[l]):
            l = j
    # Swap the found minimum element with the first element
    if(l!= i):
        m = p[i]
        p[i] = p[l]
        p[l] = m

# Calculate the sum of the first k smallest elements in the sorted array
for i in range(k):
    o += p[i]

# Print the result: the sum of the k smallest elements
print(o)

#