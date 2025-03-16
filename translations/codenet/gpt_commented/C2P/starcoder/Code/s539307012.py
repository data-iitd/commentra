# <START-OF-CODE>

# Declare variables
n, x, min, m, i = 0, 0, 0, 0, 0

# Read the number of elements (n), a value (x), and the initial minimum value (min)
n, x, min = map(int, input().split())

# Adjust x by subtracting the initial minimum value
x -= min

# Loop through the remaining n-1 elements to read their values
for i in range(1, n):
    # Read the next element into variable m
    m = int(input())

    # Subtract the current element from x
    x -= m

    # Update min if the current element is smaller than the current minimum
    if min > m:
        min = m

# Calculate and print the result based on the number of elements and the adjusted x divided by the minimum value
print(n + x // min)

# 