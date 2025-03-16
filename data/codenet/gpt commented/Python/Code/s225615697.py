# Read an integer input for the number of elements
n = int(input())

# Read a list of integers from input and convert them into a list
a = list(map(int, input().split()))

# Calculate m1 as half of the alternating sum of the list 'a'
m1 = int(sum([a[i] * ((-1)**i) for i in range(n)]) / 2)

# Convert m1 to a string for later use
result = str(m1)

# Initialize a list 'm' to store the results, with the first element set to m1
m = [None] * n
m[0] = m1

# Iterate through the range from 1 to n-1 to calculate the remaining elements of 'm'
for i in range(1, n):
    # Each element in 'm' is calculated based on the previous element and the corresponding element in 'a'
    m[i] = a[i-1] - m[i-1]

# Print the elements of 'm', each multiplied by 2, joined by spaces
print(' '.join([str(x*2) for x in m]))
