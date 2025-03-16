

import sys

def binary_search(arr, target):
    rows = len(arr)
    cols = len(arr[0])

    # Edge case: If there's only one row, search that row directly.
    if rows == 1:
        return binary_search_row(arr[0], target, 0, cols - 1)

    # Set initial boundaries for binary search on rows.
    start_row = 0
    end_row = rows - 1
    mid_col = cols // 2

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
        return binary_search_row(arr[start_row], target, 0, mid_col - 1)
    # If target is between mid_col and the last column of start_row, perform a binary
    # search on that part of the row.
    if target >= arr[start_row][mid_col + 1] and target <= arr[start_row][cols - 1]:
        return binary_search_row(arr[start_row], target, mid_col + 1, cols - 1)
    # If target is smaller than the element in the left of end_row, perform a binary
    # search on the left of end_row.
    if target <= arr[end_row][mid_col - 1]:
        return binary_search_row(arr[end_row], target, 0, mid_col - 1)
    return binary_search_row(arr[end_row], target, mid_col + 1, cols - 1)

def binary_search_row(row, target, col_start, col_end):
    while col_start <= col_end:
        mid_index = col_start + (col_end - col_start) // 2

        if row[mid_index] == target:
            return [row_index, mid_index]
        elif row[mid_index] < target:
            col_start = mid_index + 1
        else:
            col_end = mid_index - 1

    return [-1, -1]

if __name__ == "__main__":
    rows, cols = map(int, input().split())
    arr = []
    for _ in range(rows):
        arr.append(list(map(int, input().split())))
    target = int(input())
    result = binary_search(arr, target)
    print(result[0], result[1])