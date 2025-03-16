# Declare variables
n, k = map(int, input().split())
p = []

# Read n integers into the list p
for _ in range(n):
    p.append(int(input()))

# Selection sort algorithm to sort the list p in ascending order
for i in range(n):
    l = i  # Assume the minimum is the first element
    for j in range(i + 1, n):
        # Update l if a smaller element is found
        if p[j] < p[l]:
            l = j
    # Swap the found minimum element with the first element
    if l != i:
        p[i], p[l] = p[l], p[i]

# Calculate the sum of the first k smallest elements in the sorted list
o = sum(p[i] for i in range(k))

# Print the result: the sum of the k smallest elements
print(o)

# <END-OF-CODE>
