
import sys

# Function to find the maximum of the minimum of every window size in the array
def calculateMaxOfMin(arr, n):
    # Initialize the stack
    s = []
    left = [-1] * n
    right = [n] * n
    ans = [0] * (n + 1)

    # Initialize the arrays
    for i in range(n):
        left[i] = -1
        right[i] = n

    # Find the previous smaller elements
    for i in range(n):
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        if s:
            left[i] = s[-1]
        s.append(i)

    s.clear()  # Clear the stack

    # Find the next smaller elements
    for i in range(n - 1, -1, -1):
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        if s:
            right[i] = s[-1]
        s.append(i)

    # Fill the answers for all window sizes
    for i in range(n):
        len = right[i] - left[i] - 1
        ans[len] = max(ans[len], arr[i])

    # Fill the answers for smaller window sizes
    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1])

    return ans


# Main function
if __name__ == "__main__":
    # Read the array size
    n = int(sys.stdin.readline())

    # Read the array elements
    arr = list(map(int, sys.stdin.readline().strip().split()))

    # Calculate the maximum of the minimum of every window size
    result = calculateMaxOfMin(arr, n)

    # Print the result
    for i in range(1, n + 1):
        print(result[i], end=" ")

    # End of code
    print()

