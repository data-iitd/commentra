
import sys

# Initialize scanner to read input from the console
scanner = sys.stdin

# Read the number of rows and columns from the input
rows, cols = map(int, scanner.readline().split())

# Create a 2D integer array to store the input data
arr = [[0 for i in range(cols)] for j in range(rows)]

# Read the elements of the 2D array from the input
for i in range(rows):
    arr[i] = list(map(int, scanner.readline().split()))

# Read the target element to be searched in the 2D array
target = int(scanner.readline())

# Call the binarySearch method to find the indexes of the target element
result = binarySearch(arr, target)

# Print the indexes of the target element in the 2D array
print(result[0], result[1])

# Close the scanner to release the system resources
scanner.close()

# Binary search method to find the indexes of the target element in a 1D sub-array
def binarySearch(arr, target):
    start = 0
    end = len(arr) - 1

    # Continue searching until the target element is found or the search range is empty
    while start <= end:
        mid = start + (end - start) // 2

        if arr[mid] == target:
            return [mid, 0]
        elif arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1

    # Return -1, -1 if the target element is not present in the array
    return [-1, -1]

# Binary search method to find the indexes of the target element in a 2D array
def binarySearch(arr, target, row, colStart, colEnd):
    while colStart <= colEnd:
        midIndex = colStart + (colEnd - colStart) // 2

        if arr[row][midIndex] == target:
            return [row, midIndex]
        elif arr[row][midIndex] < target:
            colStart = midIndex + 1
        else:
            colEnd = midIndex - 1

    # Return -1, -1 if the target element is not present in the sub-array
    return [-1, -1]

# Binary search method to find the sub-array in which the target element may be present
def binarySearch(arr, target):
    rowCount = len(arr)
    colCount = len(arr[0])

    if rowCount == 1:
        # If the 2D array has only one row, treat it as a 1D array and call the binarySearch method for 1D array
        return binarySearch(arr[0], target)

    startRow = 0
    endRow = rowCount - 1
    midCol = colCount // 2

    # Continue searching until the target element is found or the search range is empty
    while startRow < endRow - 1:
        midRow = startRow + (endRow - startRow) // 2

        if arr[midRow][midCol] == target:
            return [midRow, midCol]
        elif arr[midRow][midCol] < target:
            startRow = midRow
        else:
            endRow = midRow

    # If the target element is found in the middle row, return its indexes
    if arr[startRow][midCol] == target:
        return [startRow, midCol]

    # If the target element is found in the last row, return its indexes
    if arr[endRow][midCol] == target:
        return [endRow, midCol]

    # If the target element is less than the middle element of the middle row, search in the left sub-array
    if target <= arr[startRow][midCol - 1]:
        return binarySearch(arr, target, startRow, 0, midCol - 1)

    # If the target element is greater than the middle element of the middle row and less than or equal to the last element of the middle column, search in the right sub-array
    if target >= arr[startRow][midCol + 1] and target <= arr[startRow][colCount - 1]:
        return binarySearch(arr, target, startRow, midCol + 1, colCount - 1)

    # If the target element is greater than the last element of the middle column, search in the sub-array of the last row
    if target > arr[startRow][colCount - 1]:
        return binarySearch(arr, target, endRow, 0, colCount - 1)

    # If the target element is less than the first element of the middle column, search in the sub-array of the first row
    return binarySearch(arr, target, startRow, 0, midCol - 1)

# 