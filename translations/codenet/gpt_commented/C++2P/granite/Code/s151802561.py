
# Read the number of elements to be sorted
n = int(input())

# Read the elements into the array A
A = list(map(int, input().split()))

# Selection sort algorithm to sort the array A
sw = 0 # Initialize the number of swaps
for i in range(n):
  mini = i # Assume the minimum is the first element of the unsorted part
  # Find the index of the minimum element in the unsorted part
  for j in range(i, n):
    if A[j] < A[mini]:
      mini = j # Update mini if a smaller element is found
  # Swap the found minimum element with the first element of the unsorted part
  t = A[i]
  A[i] = A[mini]
  A[mini] = t
  # Count the number of swaps made
  if i!= mini:
    sw += 1

# Print the sorted array
print(" ".join(map(str, A)))

# Print the total number of swaps made during sorting
print(sw)

