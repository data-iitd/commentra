# Declare variables
n, x, min_value = map(int, input().split())

# Adjust x by subtracting the initial minimum value
x -= min_value

# Loop through the remaining n-1 elements to read their values
for i in range(1, n):
    # Read the next element into variable m
    m = int(input())

    # Subtract the current element from x
    x -= m

    # Update min_value if the current element is smaller than the current minimum
    if min_value > m:
        min_value = m

# Calculate and print the result based on the number of elements and the adjusted x divided by the minimum value
print(n + x // min_value)

# <END-OF-CODE>
