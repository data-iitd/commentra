

import sys

def calculateMaxOfMin(arr, n):
    # Initialize a Stack and three arrays for storing left, right indices and answer
    s = []
    left = [-1] * n
    right = [n] * n
    ans = [0] * (n + 1)

    # Iterate through the input array using two nested loops
    for i in range(n):
        # Use a Stack to keep track of the previous index with a smaller element
        while s and arr[s[-1]] >= arr[i]:
            # Pop the previous index from the Stack
            s.pop()

        # If the Stack is not empty, update the left index for the current index
        if s:
            left[i] = s[-1]

        # Push the current index into the Stack
        s.append(i)

    # Clear the Stack for the next iteration
    s.clear()

    # Iterate through the input array again using a loop
    for i in range(n - 1, -1, -1):
        # Use a Stack to keep track of the next index with a smaller element
        while s and arr[s[-1]] >= arr[i]:
            # Pop the next index from the Stack
            s.pop()

        # If the Stack is not empty, update the right index for the current index
        if s:
            right[i] = s[-1]

        # Push the current index into the Stack
        s.append(i)

    # Initialize an empty array to store the answers
    for i in range(n):
        # Calculate the length of the current segment and update the answer accordingly
        len = right[i] - left[i] - 1
        ans[len] = max(ans[len], arr[i])

    # Update the answers for the remaining indices
    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1])

    # Return the calculated answers
    return ans

# Read the input from the standard input
n = int(input())
arr = list(map(int, input().split()))

# Call the calculateMaxOfMin function and store the result in an array
result = calculateMaxOfMin(arr, n)

# Print the results to the standard output
print(" ".join(map(str, result[1:])))

# End of code
