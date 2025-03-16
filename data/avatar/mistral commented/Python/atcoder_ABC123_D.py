# Read input: four integers x, y, z, and k followed by x * y integers each for lists a, b, and c
x, y, z, k = [int(_) for _ in input().split()]

# Initialize an empty list ab to store the sum of each element from list a with each element from list b
ab = []

# Iterate through each element in list a for i, and for each element in list b for j, append their sum to list ab
for i in range(x):
    for j in range(y):
        ab.append(a[i] + b[j])

# Sort list ab in descending order
ab.sort(reverse=True)

# Initialize an empty list abc to store the sum of each element from list ab with each element from list c
abc = []

# Iterate through each valid index i in the range of min(k, x * y), and for each index j in the range of z, append their sum to list abc
for i in range(min(k, x * y)):
    for j in range(z):
        abc.append(ab[i] + c[j])

# Sort list abc in descending order
abc.sort(reverse=True)

# Iterate through the first k elements of list abc and print each element
for i in range(k):
    print(abc[i])
