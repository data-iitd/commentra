class Main:
    @staticmethod
    def calculate_max_of_min(arr, n):
        # Initialize a Stack and three lists for storing left, right indices and answer
        stack = []
        left = [-1] * n
        right = [n] * n
        ans = [0] * (n + 1)

        # Iterate through the input array to find left indices
        for i in range(n):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            if stack:
                left[i] = stack[-1]
            stack.append(i)

        # Clear the Stack for the next iteration
        stack.clear()

        # Iterate through the input array to find right indices
        for i in range(n - 1, -1, -1):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            if stack:
                right[i] = stack[-1]
            stack.append(i)

        # Calculate the maximum of minimums for each length
        for i in range(n):
            length = right[i] - left[i] - 1
            ans[length] = max(ans[length], arr[i])

        # Update the answers for the remaining indices
        for i in range(n - 1, 0, -1):
            ans[i] = max(ans[i], ans[i + 1])

        return ans

if __name__ == "__main__":
    # Read the number of elements in the input array
    n = int(input())

    # Read the elements of the input array
    arr = list(map(int, input().split()))

    # Call the calculate_max_of_min function and store the result in a list
    result = Main.calculate_max_of_min(arr, n)

    # Print the results to the standard output
    print(" ".join(map(str, result[1:n + 1])))

# <END-OF-CODE>
