

import sys
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
def main():
    rows, cols = map(int, input().split())
    arr = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        arr[i] = list(map(int, input().split()))
    target = int(input())
    if rows == 1:
        result = binary_search(arr, target, 0, 0, cols - 1)
    else:
        start_row = 0
        end_row = rows - 1
        mid_col = cols // 2
        while start_row < end_row - 1:
            mid_row = start_row + (end_row - start_row) // 2
            if arr[mid_row][mid_col] == target:
                result = [mid_row, mid_col]
                break
            elif arr[mid_row][mid_col] < target:
                start_row = mid_row
            else:
                end_row = mid_row
        else:
            if arr[start_row][mid_col] == target:
                result = [start_row, mid_col]
            elif arr[end_row][mid_col] == target:
                result = [end_row, mid_col]
            elif target <= arr[start_row][mid_col - 1]:
                result = binary_search(arr, target, start_row, 0, mid_col - 1)
            elif target >= arr[start_row][mid_col + 1] and target <= arr[start_row][cols - 1]:
                result = binary_search(arr, target, start_row, mid_col + 1, cols - 1)
            elif target <= arr[end_row][mid_col - 1]:
                result = binary_search(arr, target, end_row, 0, mid_col - 1)
            else:
                result = binary_search(arr, target, end_row, mid_col + 1, cols - 1)
    print(result[0], result[1])
if __name__ == "__main__":
    main()
