import sys
from bisect import bisect_right

class Task:
    def solve(self, arr):
        n = len(arr)  # Number of elements in the array

        # Create a copy of the array for sorting
        sorted_arr = sorted(arr)  # Sort the array in ascending order

        total = n * (n + 1) // 2  # Calculate the total sum of elements from 1 to n^2

        l, r = 0, n - 1  # Initialize left and right pointers for binary search

        while l < r:
            mid = l + (r - l) // 2  # Calculate the middle index
            target = sorted_arr[mid]  # The middle element is the target for this iteration

            cur = 0  # Initialize current sum
            cnt = 0  # Initialize count of elements less than or equal to target

            # Initialize the bitmap array
            bit = [0] * (2 * n + 2)

            # Process each element in the original array
            for i in range(n):
                cur += 1 if arr[i] <= target else -1  # Increment the current sum if the element is less than or equal to target
                if cur + n + 1 < len(bit):
                    bit[cur + n + 1] += 1  # Increment the count for the current position

                # Count elements with sum less than or equal to current sum
                for x in range(cur + n, 0, -1):
                    cnt += bit[x]  # Add the count of elements with sum less than or equal to current sum

            if cnt >= total // 2 + 1:  # If the count is greater than half the total sum
                r = mid  # Narrow the search range to the left
            else:
                l = mid + 1  # Narrow the search range to the right

        # Return the middle element as the answer
        return sorted_arr[l]

def main():
    # Read the number of elements in the array
    N = int(sys.stdin.readline().strip())

    # Read the elements of the array
    arr = list(map(int, sys.stdin.readline().strip().split()))

    # Create an instance of the Task class and call its solve method
    tsk = Task()
    print(tsk.solve(arr))  # Print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
