# Initialize variables
N = int(input("Enter the number of elements: "))  # Read the number of elements from the standard input

A = []  # Declare an empty list to store the elements
for i in range(N):
    A.append(int(input()))  # Read each element of the array from the standard input

min_element = A[0]  # Initialize minimum element variable with first element
max_element = A[0]  # Initialize maximum element variable with first element

# Find minimum and maximum elements in the array
for i in range(N):
    if A[i] < min_element:  # If current element is smaller than the current minimum
        min_element = A[i]  # Update minimum element
    if A[i] > max_element:  # If current element is larger than the current maximum
        max_element = A[i]  # Update maximum element

# Print the difference between maximum and minimum elements
print("Difference between maximum and minimum elements:", max_element - min_element)

# <END-OF-CODE>
