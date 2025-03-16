
import sys

def calculate_max_of_min(arr, n):
    # Stack to store indices of array elements
    s = []
    # Arrays to store the nearest smaller elements to the left and right
    left = [0] * n
    right = [0] * n
    # Result array to store the maximum of minimums for each window size
    ans = [0] * (n + 1)

    # Fill the left array with indices of the nearest smaller elements
    for i in range(n):
        # Pop elements from the stack while the current element is smaller
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        # If stack is not empty, the top element is the nearest smaller element
        if s:
            left[i] = s[-1]
        # Push the current index onto the stack
        s.append(i)

    # Clear the stack to reuse it for the right array
    s.clear() 

    # Fill the right array with indices of the nearest smaller elements
    for i in range(n - 1, -1, -1):
        # Pop elements from the stack while the current element is smaller
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        # If stack is not empty, the top element is the nearest smaller element
        if s:
            right[i] = s[-1]
        # Push the current index onto the stack
        s.append(i)

    # Calculate the maximum of minimums for each window size
    for i in range(n):
        len = right[i] - left[i] - 1 # Calculate the length of the window
        ans[len] = max(ans[len], arr[i]) # Update the maximum for this window size

    # Fill in the result array to ensure each index has the maximum of minimums
    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1]) # Ensure non-increasing order

    return ans # Return the result array

# Read input from the command line arguments
n = int(sys.argv[1]) # Read the size of the array
arr = list(map(int, sys.argv[2:])) # Initialize the array

# Calculate the result using the calculate_max_of_min function
result = calculate_max_of_min(arr, n)

# Print the result for each window size
print(*result[1:]) # Print the result without the first element

# End of code
