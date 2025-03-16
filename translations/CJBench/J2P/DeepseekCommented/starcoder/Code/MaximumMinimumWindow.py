import sys

# Function to calculate the maximum of minimums for each window size
def calculateMaxOfMin(arr, n):
    # Stack to keep track of indices
    s = []
    # Arrays to store the nearest smaller element to the left and right
    left = [0] * n
    right = [0] * n
    # Array to store the maximum of minimums for different window sizes
    ans = [0] * (n + 1)

    # Setting initial values for left and right arrays
    for i in range(n):
        left[i] = -1
        right[i] = n

    # Filling the left array with nearest smaller element to the left
    for i in range(n):
        while len(s) > 0 and arr[s[-1]] >= arr[i]:
            s.pop()
        if len(s) > 0:
            left[i] = s[-1]
        s.append(i)

    # Clearing the stack for reuse
    s.clear()

    # Filling the right array with nearest smaller element to the right
    for i in range(n - 1, -1, -1):
        while len(s) > 0 and arr[s[-1]] >= arr[i]:
            s.pop()
        if len(s) > 0:
            right[i] = s[-1]
        s.append(i)

    # Updating the ans array with the maximum value for each window size
    for i in range(n):
        len = right[i] - left[i] - 1
        ans[len] = max(ans[len], arr[i])

    # Ensuring the ans array is correctly populated
    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1])

    return ans

# Main method to read input and print results
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    arr = [int(x) for x in sys.stdin.readline().split()]
    result = calculateMaxOfMin(arr, n)
    for i in range(1, n + 1):
        print(result[i], end=" ")

