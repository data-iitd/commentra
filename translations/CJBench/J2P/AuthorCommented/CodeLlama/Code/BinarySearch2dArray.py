

import sys


def binary_search(arr, target):
    """
    Performs a binary search on a 2D sorted array to find the target value.
    The array must be sorted in ascending order in both rows and columns.

    :param arr: The 2D array to search in.
    :param target: The value to search for.
    :return: An array containing the row and column indices of the target, or [-1,
    -1] if the target is not found.
    """
    row_count = len(arr)
    col_count = len(arr[0])

    # Edge case: If there's only one row, search that row directly.
    if row_count == 1:
        return binary_search(arr, target, 0, 0, col_count - 1)

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
    # startRow and endRow.
    if arr[start_row][mid_col] == target:
        return [start_row, mid_col]
    if arr[end_row][mid_col] == target:
        return [end_row, mid_col]

    # If target is smaller than the element in the left of startRow, perform a
    # binary search on the left of startRow.
    if target <= arr[start_row][mid_col - 1]:
        return binary_search(arr, target, start_row, 0, mid_col - 1)
    # If target is between midCol and the last column of startRow, perform a binary
    # search on that part of the row.
    if target >= arr[start_row][mid_col + 1] and target <= arr[start_row][col_count - 1]:
        return binary_search(arr, target, start_row, mid_col + 1, col_count - 1)
    # If target is smaller than the element in the left of endRow, perform a binary
    # search on the left of endRow.
    if target <= arr[end_row][mid_col - 1]:
        return binary_search(arr, target, end_row, 0, mid_col - 1)
    return binary_search(arr, target, end_row, mid_col + 1, col_count - 1)


def binary_search_row(arr, target, row, col_start, col_end):
    """
    Performs a binary search on a specific row of the 2D array.

    :param arr: The 2D array to search in.
    :param target: The value to search for.
    :param row: The row index where the target will be searched.
    :param col_start: The starting column index for the search.
    :param col_end: The ending column index for the search.
    :return: An array containing the row and column indices of the target, or [-1,
    -1] if the target is not found.
    """
    while col_start <= col_end:
        mid_index = col_start + (col_end - col_start) // 2

        if arr[row][mid_index] == target:
            return [row, mid_index]
        elif arr[row][mid_index] < target:
            col_start = mid_index + 1
        else:
            col_end = mid_index - 1

    return [-1, -1]


if __name__ == "__main__":
    # Input: Number of rows and columns
    row_count, col_count = map(int, input().split())
    arr = []

    # Input: 2D array elements
    for _ in range(row_count):
        arr.append(list(map(int, input().split())))

    # Input: Target value to search
    target = int(input())

    # Perform binary search
    result = binary_search(arr, target)

    # Output: Target position or [-1, -1] if not found
    print(" ".join(map(str, result)))


