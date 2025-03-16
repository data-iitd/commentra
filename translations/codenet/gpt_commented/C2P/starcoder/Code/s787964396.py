# Define a constant for the maximum range of input values
I = 10000

# Function to perform Counting Sort
def CountingSort(a, b, k):
    c = [0] * (I + 1) # Initialize the counting array 'c' to zero

    # Count occurrences of each element in array 'a'
    for j in range(k):
        c[a[j + 1]] += 1 # Increment the count for each element

    # Update the counting array 'c' to contain the actual positions of elements
    for i in range(1, I + 1):
        c[i] += c[i - 1] # Cumulative sum to determine positions

    # Build the output array 'b' using the counting array 'c'
    for j in range(k, 0, -1):
        b[c[a[j]]] = a[j] # Place the elements in their sorted position
        c[a[j]] -= 1 # Decrement the count for the current element

# Read the number of elements to be sorted
n = int(input())

# Allocate memory for the input array 'a' and output array 'b'
a = [0] * (n + 1)
b = [0] * (n + 1)

# Read 'n' elements into the array 'a'
for i in range(n):
    a[i + 1] = int(input()) # Store elements starting from index 1

# Call the CountingSort function to sort the array 'a' and store the result in 'b'
CountingSort(a, b, n)

# Print the sorted elements from array 'b'
print(b[1], end = " ") # Print the first sorted element
for i in range(2, n + 1):
    print(b[i], end = " ") # Print the remaining sorted elements
print()

# 