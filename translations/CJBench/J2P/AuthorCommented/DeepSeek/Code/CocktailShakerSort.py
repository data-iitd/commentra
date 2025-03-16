def cocktail_shaker_sort(arr):
    if len(arr) == 0:
        return arr

    left = 0
    right = len(arr) - 1

    while left < right:
        right = perform_forward_pass(arr, left, right)
        left = perform_backward_pass(arr, left, right)

    return arr

def perform_forward_pass(arr, left, right):
    last_swapped_index = left
    for i in range(left, right):
        if arr[i] > arr[i + 1]:
            arr[i], arr[i + 1] = arr[i + 1], arr[i]
            last_swapped_index = i
    return last_swapped_index

def perform_backward_pass(arr, left, right):
    last_swapped_index = right
    for i in range(right, left, -1):
        if arr[i] < arr[i - 1]:
            arr[i], arr[i - 1] = arr[i - 1], arr[i]
            last_swapped_index = i
    return last_swapped_index

# Example usage:
# arr = [5, 3, 8, 4, 2]
# sorted_arr = cocktail_shaker_sort(arr)
# print(sorted_arr)

