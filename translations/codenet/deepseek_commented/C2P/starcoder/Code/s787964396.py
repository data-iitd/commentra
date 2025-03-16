# Define a constant I with the value 10000
I = 10000

# Function to perform Counting Sort
def CountingSort(a, b, k):
  c = [0] * (I + 1)
  
  # Initialize array c to store the count of each element
  for i in range(I + 1):
    c[i] = 0
  
  # Count the occurrences of each element in array a
  for j in range(k):
    c[a[j + 1]] += 1
  
  # Compute the cumulative count to determine the positions of elements in the sorted array
  for i in range(1, I + 1):
    c[i] += c[i - 1]
  
  # Place elements into array b in sorted order
  for j in range(k, 0, -1):
    b[c[a[j]]] = a[j]
    c[a[j]] -= 1

# Read the number of elements
n = int(input())

# Dynamically allocate memory for arrays a and b
a = [0] * (n + 1)
b = [0] * (n + 1)

# Read elements into array a starting from index 1 to n
for i in range(n):
  a[i + 1] = int(input())

# Call CountingSort function to sort the array
CountingSort(a, b, n)

# Print the sorted elements starting from index 1 to n
print(b[1], end = " ")
for i in range(2, n + 1):
  print(b[i], end = " ")
print()

