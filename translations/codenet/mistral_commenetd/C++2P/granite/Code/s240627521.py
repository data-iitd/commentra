

N = int(input()) # Read the number of elements from the standard input
A = [int(input()) for _ in range(N)] # Read the elements into a list A
A.sort(reverse=True) # Sort the list A in descending order
max_diff = float('inf') # Initialize the maximum difference to an infinite value
index = None # Initialize the index of the second smallest element to None
for i in range(1, N): # Iterate through the range [1, N)
    diff = abs(A[0]-2*A[i]) # Calculate the difference between the smallest and the ith element
    if diff > max_diff: # Check if the current difference is greater than the maximum difference
        max_diff = diff # Update the maximum difference if it is
        index = i # Update the index of the second smallest element
print(A[0], A[index]) # Output the smallest and second smallest elements

