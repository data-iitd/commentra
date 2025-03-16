import sys

# Function to calculate the maximum of minimums for all window sizes
def calculateMaxOfMin(arr, n):
    # Stack to store indices of array elements
    s = []
    # Arrays to store the nearest smaller elements to the left and right
    left = [0] * n
    right = [0] * n
    # Result array to store the maximum of minimums for each window size
    ans = [0] * (n + 1)

    # Initialize left and right arrays
    for i in range(n):
        left[i] = -1 # Default value for left
        right[i] = n # Default value for right

    # Fill the left array with indices of the nearest smaller elements
    for i in range(n):
        # Pop elements from the stack while the current element is smaller
        while len(s) > 0 and arr[s[-1]] >= arr[i]:
            s.pop()
        # If stack is not empty, the top element is the nearest smaller element
        if len(s) > 0:
            left[i] = s[-1]
        # Push the current index onto the stack
        s.append(i)

    # Clear the stack to reuse it for the right array
    s.clear() 

    # Fill the right array with indices of the nearest smaller elements
    for i in range(n - 1, -1, -1):
        # Pop elements from the stack while the current element is smaller
        while len(s) > 0 and arr[s[-1]] >= arr[i]:
            s.pop()
        # If stack is not empty, the top element is the nearest smaller element
        if len(s) > 0:
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

# Main function
if __name__ == '__main__':
    # Read the size of the array
    n = int(input())
    # Read the elements of the array
    arr = [int(x) for x in input().split()]
    # Calculate the result using the calculateMaxOfMin method
    result = calculateMaxOfMin(arr, n)
    # Print the result for each window size
    for i in range(1, n + 1):
        print(result[i], end=' ')

