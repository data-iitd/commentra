
import sys

# Main class with a private constructor to prevent instantiation from outside
class Main:
    def __init__(self):
        pass

    # Method to count the number of inversions in an array using merge sort algorithm
    @staticmethod
    def count_inversions(arr):
        return Main.merge_sort_and_count(arr, 0, len(arr) - 1)

    # Recursive helper method for merge sort and counting inversions
    @staticmethod
    def merge_sort_and_count(arr, left, right):
        if left >= right:  # Base case: when the subarray has only one element or is empty
            return 0

        mid = (left + right) // 2  # Calculate the middle index of the subarray

        # Recursively merge sort and count inversions in left and right halves
        inversions = 0
        inversions += Main.merge_sort_and_count(arr, left, mid)
        inversions += Main.merge_sort_and_count(arr, mid + 1, right)

        # Merge the sorted halves and count inversions
        inversions += Main.merge_and_count(arr, left, mid, right)

        return inversions

    # Merge and count inversions in two sorted halves
    @staticmethod
    def merge_and_count(arr, left, mid, right):
        left_arr = [0] * (mid - left + 1)  # Create temporary arrays for merging
        right_arr = [0] * (right - mid)

        # Copy elements from the original array to temporary arrays
        left_arr[:] = arr[left:mid + 1]
        right_arr[:] = arr[mid + 1:right + 1]

        i = 0  # Index for left array
        j = 0  # Index for right array
        k = left  # Index for the merged array
        inversions = 0  # Initialize inversions counter

        # Merge the sorted halves and count inversions
        while i < len(left_arr) and j < len(right_arr):
            if left_arr[i] <= right_arr[j]:  # If current elements are in non-decreasing order
                arr[k] = left_arr[i]  # Copy the smaller element to the merged array
                i += 1
            else:  # If current elements are in non-increasing order
                arr[k] = right_arr[j]  # Copy the larger element to the merged array
                j += 1
                inversions += mid + 1 - left - i

        # Copy remaining elements from left and right arrays to the merged array
        while i < len(left_arr):
            arr[k] = left_arr[i]
            i += 1
            k += 1
        while j < len(right_arr):
            arr[k] = right_arr[j]
            j += 1
            k += 1

        return inversions

    # Main method to read input and print the result
    @staticmethod
    def main():
        n = int(sys.stdin.readline())  # Read the number of elements in the array
        arr = [int(x) for x in sys.stdin.readline().split()]  # Read elements of the array and store them in the array

        result = Main.count_inversions(arr)  # Call the count_inversions method to find the number of inversions
        print("Number of inversions:", result)  # Print the result


if __name__ == "__main__":
    Main.main()

