
import sys

def calculate_max_of_min(arr, n):
    s = []
    left = [0] * n
    right = [0] * n

    # Initialize arrays
    for i in range(n):
        left[i] = -1
        right[i] = n

    # Find previous smaller elements
    for i in range(n):
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        if s:
            left[i] = s[-1]
        s.append(i)

    s.clear() # Clear the stack

    # Find next smaller elements
    for i in range(n - 1, -1, -1):
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        if s:
            right[i] = s[-1]
        s.append(i)

    # Fill the answers for all window sizes
    ans = [0] * (n + 1)
    for i in range(n):
        len = right[i] - left[i] - 1 # Window size
        ans[len] = max(ans[len], arr[i])

    # Fill the answers for smaller window sizes
    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1])

    return ans

if __name__ == "__main__":
    # Read array size
    n = int(input())

    # Read array elements
    arr = list(map(int, input().split()))

    # Calculate maximum of minimums
    result = calculate_max_of_min(arr, n)

    # Print the result
    print(*result[1:])

