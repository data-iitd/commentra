class Main:
    @staticmethod
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
            while s and arr[s[-1]] >= arr[i]:
                s.pop()
            if s:
                left[i] = s[-1]
            s.append(i)

        # Clear the stack to reuse it for the right array
        s.clear()

        # Fill the right array with indices of the nearest smaller elements
        for i in range(n - 1, -1, -1):
            while s and arr[s[-1]] >= arr[i]:
                s.pop()
            if s:
                right[i] = s[-1]
            s.append(i)

        # Calculate the maximum of minimums for each window size
        for i in range(n):
            length = right[i] - left[i] - 1  # Calculate the length of the window
            ans[length] = max(ans[length], arr[i])  # Update the maximum for this window size

        # Fill in the result array to ensure each index has the maximum of minimums
        for i in range(n - 1, 0, -1):
            ans[i] = max(ans[i], ans[i + 1])  # Ensure non-increasing order

        return ans  # Return the result array

if __name__ == "__main__":
    # Create a scanner to read input
    n = int(input())  # Read the size of the array
    arr = list(map(int, input().split()))  # Read the elements of the array

    # Calculate the result using the calculate_max_of_min method
    result = Main.calculate_max_of_min(arr, n)

    # Print the result for each window size
    print(" ".join(map(str, result[1:n + 1])))

# <END-OF-CODE>
