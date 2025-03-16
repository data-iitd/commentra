
import sys

def main():
    # Read the number of rows and columns for the 2D array
    rows, cols = map(int, input().split())
    
    # Initialize a 2D array with the specified dimensions
    arr = [[0] * cols for _ in range(rows)]
    
    # Populate the 2D array with user input
    for i in range(rows):
        arr[i] = list(map(int, input().split()))
    
    # Read the target value to search for in the array
    target = int(input())
    
    # Perform binary search to find the target in the 2D array
    result = binary_search(arr, target)
    
    # Output the result, which contains the row and column indices of the target
    print(result[0], result[1])

def binary_search(arr, target):
    rows = len(arr) # Get the number of rows in the array
    cols = len(arr[0]) # Get the number of columns in the array
    
    # If there is only one row, perform a binary search in that row
    if rows == 1:
        return binary_search(arr[0], target, 0, 0, cols - 1)
    
    # Initialize pointers for the rows
    start_row = 0
    end_row = rows - 1
    mid_col = cols // 2 # Calculate the middle column index
    
    # Perform binary search on the rows
    while start_row < end_row - 1:
        mid_row = start_row + (end_row - start_row) // 2 # Calculate the middle row index
        
        # Check if the target is found at the middle column of the mid_row
        if arr[mid_row][mid_col] == target:
            return [mid_row, mid_col] # Return the found position
        elif arr[mid_row][mid_col] < target:
            start_row = mid_row # Move the start row pointer up
        else:
            end_row = mid_row # Move the end row pointer down
    
    # Check if the target is found in the start_row or end_row at the mid_col
    if arr[start_row][mid_col] == target:
        return [start_row, mid_col]
    if arr[end_row][mid_col] == target:
        return [end_row, mid_col]
    
    # Determine which sub-column to search next based on the target's value
    if target <= arr[start_row][mid_col - 1]:
        return binary_search(arr[start_row], target, 0, 0, mid_col - 1) # Search left sub-column
    if target >= arr[start_row][mid_col + 1] and target <= arr[start_row][cols - 1]:
        return binary_search(arr[start_row], target, mid_col + 1, cols - 1) # Search right sub-column
    if target <= arr[end_row][mid_col - 1]:
        return binary_search(arr[end_row], target, 0, 0, mid_col - 1) # Search left sub-column in end_row
    # Search right sub-column in end_row
    return binary_search(arr[end_row], target, mid_col + 1, cols - 1)

def binary_search(arr, target, row, col_start, col_end):
    # Perform binary search in the specified row between col_start and col_end
    while col_start <= col_end:
        mid_index = col_start + (col_end - col_start) // 2 # Calculate the middle index
        
        # Check if the target is found at mid_index
        if arr[row][mid_index] == target:
            return [row, mid_index] # Return the found position
        elif arr[row][mid_index] < target:
            col_start = mid_index + 1 # Move the start column pointer up
        else:
            col_end = mid_index - 1 # Move the end column pointer down
    
    # Return -1, -1 if the target is not found
    return [-1, -1]

if __name__ == "__main__":
    main()

