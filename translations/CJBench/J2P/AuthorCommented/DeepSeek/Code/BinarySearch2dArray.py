def binary_search(arr, target):
    row_count = len(arr)
    col_count = len(arr[0])

    # Edge case: If there's only one row, search that row directly.
    if row_count == 1:
        return binary_search_row(arr, target, 0, 0, col_count - 1)

    # Set initial boundaries for binary search on rows.
    start_row = 0
    end_row = row_count - 1
    mid_col = col_count // 2

    # Perform binary search on rows based on the middle column.
    while start_row < end_row - 1:
        mid_row = start_row + (end_row - start_row) // 2

        if arr[mid_row][mid_col] == target:
            return [mid_row, mid_col]
        elif arr[mid_row][mid_col] < target:
            start_row = mid_row
        else:
            end_row = mid_row

    # If the target wasn't found during the row search, check the middle column of
    # start_row and end_row.
    if arr[start_row][mid_col] == target:
        return [start_row, mid_col]
    if arr[end_row][mid_col] == target:
        return [end_row, mid_col]

    # If target is smaller than the element in the left of start_row, perform a
    # binary search on the left of start_row.
    if target <= arr[start_row][mid_col - 1]:
        return binary_search_row(arr, target, start_row, 0, mid_col - 1)
    # If target is between mid_col and the last column of start_row, perform a binary
    # search on that part of the row.
    if target >= arr[start_row][mid_col + 1] and target <= arr[start_row][col_count - 1]:
        return binary_search_row(arr, target, start_row, mid_col + 1, col_count - 1)
    # If target is smaller than the element in the left of end_row, perform a binary
    # search on the left of end_row.
    if target <= arr[end_row][mid_col - 1]:
        return binary_search_row(arr, target, end_row, 0, mid_col - 1)
    return binary_search_row(arr, target, end_row, mid_col + 1, col_count - 1)


def binary_search_row(arr, target, row, col_start, col_end):
    while col_start <= col_end:
        mid_index = col_start + (col_end - col_start) // 2

        if arr[row][mid_index] == target:
            return [row, mid_index]
        elif arr[row][mid_index] < target:
            col_start = mid_index + 1
        else:
            col_end = mid_index - 1

    return [-1, -1]


# Example usage:
# rows, cols = map(int, input().split())
# arr = []
# for _ in range(rows):
#     row = list(map(int, input().split()))
#     arr.append(row)
# target = int(input())
# result = binary_search(arr, target)
# print(result[0], result[1])

