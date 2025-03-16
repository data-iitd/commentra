
import sys

def calculate_max_of_min(arr, n):
    # Initialize a Stack and three arrays for storing left, right indices and answer
    s = []
    left = [-1] * n
    right = [n] * n
    ans = [0] * (n + 1)

    # Initialize left and right arrays with default values
    for i in range(n):
        left[i] = -1
        right[i] = n

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
    for i in range(n - 1, -1, -1):
        ans[i] = max(ans[i], ans[i + 1])

    # Return the calculated answers
    return ans

def main():
    # Read the number of elements in the input array
    n = int(sys.stdin.readline())

    # Allocate memory for the input array
    arr = [0] * n

    # Read the elements of the input array
    for i in range(n):
        arr[i] = int(sys.stdin.readline())

    # Call the calculateMaxOfMin function and store the result in an array
    result = calculate_max_of_min(arr, n)

    # Print the results to the standard output
    for i in range(1, n + 1):
        print(result[i], end=" ")

    # End of code
    print("