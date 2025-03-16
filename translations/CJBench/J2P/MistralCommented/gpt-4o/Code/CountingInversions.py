class Main:
    @staticmethod
    def count_inversions(arr):
        return Main.merge_sort_and_count(arr, 0, len(arr) - 1)

    @staticmethod
    def merge_sort_and_count(arr, left, right):
        if left >= right:  # Base case: when the subarray has only one element or is empty
            return 0

        mid = left + (right - left) // 2  # Calculate the middle index of the subarray

        # Recursively merge sort and count inversions in left and right halves
        inversions = 0
        inversions += Main.merge_sort_and_count(arr, left, mid)
        inversions += Main.merge_sort_and_count(arr, mid + 1, right)

        # Merge the sorted halves and count inversions
        inversions += Main.merge_and_count(arr, left, mid, right)

        return inversions

    @staticmethod
    def merge_and_count(arr, left, mid, right):
        left_arr = arr[left:mid + 1]  # Create temporary arrays for merging
        right_arr = arr[mid + 1:right + 1]

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
                inversions += (mid + 1) - left - i  # Count the number of inversions caused by this swap
                j += 1
            k += 1

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
if __name__ == "__main__":
    n = int(input("Enter the number of elements in the array: "))  # Read the number of elements in the array
    arr = list(map(int, input("Enter the elements of the array: ").split()))  # Read elements of the array

    result = Main.count_inversions(arr)  # Call the count_inversions method to find the number of inversions
    print("Number of inversions:", result)  # Print the result

# <END-OF-CODE>
