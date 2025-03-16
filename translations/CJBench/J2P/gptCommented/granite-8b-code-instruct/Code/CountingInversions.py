
import sys

def merge_sort_and_count(arr, left, right):
    # Base case: if the left index is greater than or equal to the right index
    if left >= right:
        return 0  # No inversions

    # Calculate the middle index
    mid = left + (right - left) // 2
    inversions = 0

    # Recursively count inversions in the left half
    inversions += merge_sort_and_count(arr, left, mid)
    # Recursively count inversions in the right half
    inversions += merge_sort_and_count(arr, mid + 1, right)
    # Count inversions while merging the two halves
    inversions += merge_and_count(arr, left, mid, right)

    return inversions  # Return total inversions

def merge_and_count(arr, left, mid, right):
    # Create temporary arrays for left and right halves
    left_arr = arr[left:mid + 1]
    right_arr = arr[mid + 1:right + 1]

    # Initialize pointers for left, right, and merged array
    i = 0  # Pointer for left_arr
    j = 0  # Pointer for right_arr
    k = left  # Pointer for the main array
    inversions = 0  # Count of inversions

    # Merge the two halves while counting inversions
    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] <= right_arr[j]:
            arr[k] = left_arr[i]  # No inversion, copy element from left_arr
            i += 1
        else:
            arr[k] = right_arr[j]  # Inversion found, copy element from right_arr
            inversions += mid + 1 - left - i  # Count inversions: all remaining elements in left_arr are greater
            j += 1
        k += 1

    # Copy remaining elements of left_arr, if any
    arr[k:] = left_arr[i:]

    # Copy remaining elements of right_arr, if any
    arr[k:] = right_arr[j:]

    return inversions  # Return the count of inversions

def count_inversions(arr):
    return merge_sort_and_count(arr, 0, len(arr) - 1)

if __name__ == "__main__":
    # Read the number of elements in the array
    n = int(input())
    arr = list(map(int, input().split()))

    # Count inversions in the array and store the result
    result = count_inversions(arr)
    # Output the number of inversions
    print("Number of inversions:", result)