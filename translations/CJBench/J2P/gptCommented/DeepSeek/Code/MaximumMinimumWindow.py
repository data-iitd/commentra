def calculate_max_of_min(arr, n):
    # Stack to store indices of array elements
    s = []
    # Arrays to store the nearest smaller elements to the left and right
    left = [-1] * n
    right = [n] * n
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
        length = right[i] - left[i] - 1
        ans[length] = max(ans[length], arr[i])

    # Fill in the result array to ensure each index has the maximum of minimums
    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1])

    return ans


def main():
    # Create a scanner to read input
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the size of the array
    arr = [int(x) for x in data[1:n+1]]  # Initialize the array

    # Calculate the result using the calculateMaxOfMin method
    result = calculate_max_of_min(arr, n)

    # Print the result for each window size
    for i in range(1, n + 1):
        print(result[i], end=" ")


if __name__ == "__main__":
    main()
