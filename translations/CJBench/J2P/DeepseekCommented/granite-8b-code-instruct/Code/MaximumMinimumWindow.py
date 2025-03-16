
import sys

def calculate_max_of_min(arr, n):
    # Stack to keep track of indices
    s = []
    # Arrays to store the nearest smaller element to the left and right
    left = [-1] * n
    right = [n] * n
    # Array to store the maximum of minimums for different window sizes
    ans = [0] * (n + 1)

    # Setting initial values for left and right arrays
    for i in range(n):
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        if s:
            left[i] = s[-1]
        s.append(i)

    # Clearing the stack for reuse
    s.clear()

    # Filling the right array with nearest smaller element to the right
    for i in range(n - 1, -1, -1):
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        if s:
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
def main():
    n = int(input())
    arr = list(map(int, input().split()))
    result = calculate_max_of_min(arr, n)
    print(*result[1:])

if __name__ == "__main__":
    main()

