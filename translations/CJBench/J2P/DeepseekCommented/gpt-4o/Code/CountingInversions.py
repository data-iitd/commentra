def count_inversions(arr):
    return merge_sort_and_count(arr, 0, len(arr) - 1)


def merge_sort_and_count(arr, left, right):
    if left >= right:
        return 0  # Base case: no inversions in a single element array
    mid = left + (right - left) // 2
    inversions = 0
    inversions += merge_sort_and_count(arr, left, mid)  # Count inversions in the left half
    inversions += merge_sort_and_count(arr, mid + 1, right)  # Count inversions in the right half
    inversions += merge_and_count(arr, left, mid, right)  # Count inversions during merge
    return inversions


def merge_and_count(arr, left, mid, right):
    left_arr = arr[left:mid + 1]
    right_arr = arr[mid + 1:right + 1]
    i = 0
    j = 0
    k = left
    inversions = 0
    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] <= right_arr[j]:
            arr[k] = left_arr[i]  # No inversion, copy from left_arr
            i += 1
        else:
            arr[k] = right_arr[j]  # Inversion found, copy from right_arr
            j += 1
            inversions += mid + 1 - left - i  # Count inversions
        k += 1
    while i < len(left_arr):
        arr[k] = left_arr[i]  # Copy remaining elements from left_arr
        i += 1
        k += 1
    while j < len(right_arr):
        arr[k] = right_arr[j]  # Copy remaining elements from right_arr
        j += 1
        k += 1
    return inversions


def main():
    n = int(input())  # Read the size of the array
    arr = list(map(int, input().split()))  # Read the array elements
    result = count_inversions(arr)  # Compute the number of inversions
    print("Number of inversions:", result)  # Print the result


main()
