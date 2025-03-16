# Read the number of elements
n = int(input())

# Read n integers into array a
a = [int(x) for x in input().split()]

# Read n integers into array b
b = [int(x) for x in input().split()]

# Initialize sum
sum = 0

# Iterate over all elements of a
for i in range(n):
    # Check if a[i] is greater than b[i]
    if a[i] - b[i] > 0:
        # Add the difference to sum
        sum += a[i] - b[i]

# Output the sum
print(sum)

