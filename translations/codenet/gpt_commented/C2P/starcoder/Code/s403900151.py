# <START-OF-CODE>

# Declare variables for input values and loop counters
n, r, p, c = 0, 0, 0, 0
i, j, k, l = 0, 0, 0, 0
a = [0] * 51 # Arrays to hold values
b = [0] * 51

# Infinite loop to continuously accept input until a termination condition is met
while True:
    # Read the values of n (number of elements) and r (number of operations)
    n, r = map(int, input().split())

    # Check for termination condition: if both n and r are zero, exit the loop
    if not n and not r:
        break

    # Initialize array a with values from 1 to n
    for i in range(n):
        a[i] = i + 1

    # Process each operation
    for i in range(r):
        # Read the values of p (number of elements to move) and c (number of elements to copy)
        p, c = map(int, input().split())

        # Temporary array b to hold the elements that will be moved
        for j in range(c):
            b[j] = a[n - p - c + 1 + j] # Copy elements from a to b

        # Shift elements in array a to make space for the new elements
        for j in range(p - 1):
            a[n - p - c + 1 + j] = a[n - p + j + 1] # Move elements to the left

        # Insert the copied elements from b back into array a
        for j in range(n - p - c + 1 + j, n - p - c + 1 + j + c):
            a[j] = b[j - n + p - c + 1] # Place elements from b into the correct position in a

    # Print the last element of array a after all operations are completed
    print(a[n - 1])

# 