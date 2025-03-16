
# Initialize variables
N = int(input()) # Number of elements in the array
A = [int(input()) for i in range(N)] # Declare and initialize an array of size N

min_element = A[0] # Initialize minimum element variable with first element
max_element = A[0] # Initialize maximum element variable with first element

# Find minimum and maximum elements in the array
for i in range(N):
    if A[i] < min_element: # If current element is smaller than the current minimum
        min_element = A[i] # Update minimum element
    if A[i] > max_element: # If current element is larger than the current maximum
        max_element = A[i] # Update maximum element

# Print the difference between maximum and minimum elements
print("Difference between maximum and minimum elements: " + str(max_element - min_element))

