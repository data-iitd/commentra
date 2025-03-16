class Main:
    @staticmethod
    def calculate_max_of_min(arr, n):
        s = []
        left = [-1] * n
        right = [n] * n
        ans = [0] * (n + 1)

        # Find previous smaller elements
        for i in range(n):
            while s and arr[s[-1]] >= arr[i]:
                s.pop()
            if s:
                left[i] = s[-1]
            s.append(i)

        s.clear()  # Clear the stack

        # Find next smaller elements
        for i in range(n - 1, -1, -1):
            while s and arr[s[-1]] >= arr[i]:
                s.pop()
            if s:
                right[i] = s[-1]
            s.append(i)

        # Fill the answers for all window sizes
        for i in range(n):
            length = right[i] - left[i] - 1  # Window size
            ans[length] = max(ans[length], arr[i])

        # Fill the answers for smaller window sizes
        for i in range(n - 1, 0, -1):
            ans[i] = max(ans[i], ans[i + 1])

        return ans

if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))

    # Read array elements
    arr = list(map(int, input("Enter the elements of the array: ").split()))

    # Calculate maximum of minimums
    result = Main.calculate_max_of_min(arr, n)

    # Print the result
    print(" ".join(map(str, result[1:n + 1])))

# <END-OF-CODE>
