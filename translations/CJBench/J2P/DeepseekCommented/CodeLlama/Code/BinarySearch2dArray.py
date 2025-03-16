
import sys

def binary_search(arr, target):
    rows = len(arr)
    cols = len(arr[0])
    if rows == 1:
        return binary_search(arr, target, 0, 0, cols - 1)
    start_row = 0
    end_row = rows - 1
    mid_col = cols // 2
    while start_row < end_row - 1:
        mid_row = start_row + (end_row - start_row) // 2
        if arr[mid_row][mid_col] == target:
            return [mid_row, mid_col]
        elif arr[mid_row][mid_col] < target:
            start_row = mid_row
        else:
            end_row = mid_row
    if arr[start_row][mid_col] == target:
        return [start_row, mid_col]
    elif arr[end_row][mid_col] == target:
        return [end_row, mid_col]
    elif target <= arr[start_row][mid_col - 1]:
        return binary_search(arr, target, start_row, 0, mid_col - 1)
    elif target >= arr[start_row][mid_col + 1] and target <= arr[start_row][cols - 1]:
        return binary_search(arr, target, start_row, mid_col + 1, cols - 1)
    elif target <= arr[end_row][mid_col - 1]:
        return binary_search(arr, target, end_row, 0, mid_col - 1)
    return binary_search(arr, target, end_row, mid_col + 1, cols - 1)

def binary_search(arr, target, row, col_start, col_end):
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
    scanner = sys.stdin
    rows = int(scanner.readline())
    cols = int(scanner.readline())
    arr = []
    for _ in range(rows):
        arr.append([int(x) for x in scanner.readline().split()])
    target = int(scanner.readline())
    result = binary_search(arr, target)
    print(" ".join(map(str, result)))

