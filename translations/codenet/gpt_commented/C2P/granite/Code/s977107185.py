
# Read the number of elements to be sorted
N = int(input())

# Input the elements into the list A
A = list(map(int, input().split()))

# Perform bubble sort on the list A
for i in range(N - 1):
  for j in range(N - 1, i, -1):
    # Compare adjacent elements and swap if they are in the wrong order
    if A[j] < A[j - 1]:
      A[j], A[j - 1] = A[j - 1], A[j]

# Output the sorted list
print(" ".join(map(str, A)))

# Print the total number of swaps made during sorting
count = 0
for i in range(N - 1):
  for j in range(N - 1, i, -1):
    if A[j] < A[j - 1]:
      count += 1
print(count)

