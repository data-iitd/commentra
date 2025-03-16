# Read integers x, y, z, and k from input
x, y, z, k = [int(_) for _ in input().split()]

# Read list a of size x from input
a = [int(_) for _ in input().split()]

# Read list b of size y from input
b = [int(_) for _ in input().split()]

# Read list c of size z from input
c = [int(_) for _ in input().split()]

# Initialize an empty list to store the sums of elements from lists a and b
ab = []

# Calculate all possible sums of elements from list a and list b
for i in range(x):
    for j in range(y):
        ab.append(a[i] + b[j])

# Sort the list of sums in descending order
ab.sort(reverse=True)

# Initialize an empty list to store the sums of the top k elements from ab and elements from list c
abc = []

# Calculate sums of the top k elements from ab with each element in c
for i in range(min(k, x * y)):
    for j in range(z):
        abc.append(ab[i] + c[j])

# Sort the resulting sums in descending order
abc.sort(reverse=True)

# Print the top k sums from the final list abc
for i in range(k):
    print(abc[i])
