
# Python code to implement Bubble Sort

N = int(input("Enter the size of the array: ")) # Read the size of the array

A = [] # Initialize an empty list to store the array elements

for i in range(N):
  A.append(int(input("Enter element " + str(i+1) + ": "))) # Read the elements of the array

count = 0 # Initialize the swap counter

# Implement Bubble Sort
for i in range(N - 1):
  for j in range(N - 1, i, -1):
    if A[j] < A[j - 1]:
      A[j], A[j - 1] = A[j - 1], A[j] # Swap A[j] and A[j-1]
      count += 1 # Increment the swap counter

print("Sorted array:", A) # Print the sorted array elements

print("Number of swaps:", count) # Print the number of swaps

