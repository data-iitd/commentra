import sys

def main():
    # Read the number of rows and columns for the 2D array
    rows, cols = map(int, sys.stdin.readline().split())
    
    # Initialize a 2D array with the specified dimensions
    arr = [[0 for _ in range(cols)] for _ in range(rows)]
    
    # Populate the 2D array with user input
    for i in range(rows):
        for j in range(cols):
            arr[i][j] = int(sys.stdin.readline())
    
    # Read the target value to search for in the array
    target = int(sys.stdin.readline())
    
    # Perform binary search to find the target in the 2D array
    result = binarySearch(arr, target)
    
    # Output the result, which contains the row and column indices of the target
    print(result[0], result[1])

def binarySearch(arr, target):
    rowCount = len(arr) # Get the number of rows in the array
    colCount = len(arr[0]) # Get the number of columns in the array
    
    # If there is only one row, perform a binary search in that row
    if rowCount == 1:
        return binarySearch(arr, target, 0, 0, colCount - 1)
    
    # Initialize pointers for the rows
    startRow = 0
    endRow = rowCount - 1
    midCol = colCount // 2 # Calculate the middle column index
    
    # Perform binary search on the rows
    while startRow < endRow - 1:
        midRow = startRow + (endRow - startRow) // 2 # Calculate the middle row index
        
        # Check if the target is found at the middle column of the midRow
        if arr[midRow][midCol] == target:
            return [midRow, midCol] # Return the found position
        elif arr[midRow][midCol] < target:
            startRow = midRow # Move the start row pointer up
        else:
            endRow = midRow # Move the end row pointer down
    
    # Check if the target is found in the startRow or endRow at the midCol
    if arr[startRow][midCol] == target:
        return [startRow, midCol]
    if arr[endRow][midCol] == target:
        return [endRow, midCol]
    
    # Determine which sub-column to search next based on the target's value
    if target <= arr[startRow][midCol - 1]:
        return binarySearch(arr, target, startRow, 0, midCol - 1) # Search left sub-column
    if target >= arr[startRow][midCol + 1] and target <= arr[startRow][colCount - 1]:
        return binarySearch(arr, target, startRow, midCol + 1, colCount - 1) # Search right sub-column
    if target <= arr[endRow][midCol - 1]:
        return binarySearch(arr, target, endRow, 0, midCol - 1) # Search left sub-column in endRow
    
    # Search right sub-column in endRow
    return binarySearch(arr, target, endRow, midCol + 1, colCount - 1)

def binarySearch(arr, target, row, colStart, colEnd):
    # Perform binary search in the specified row between colStart and colEnd
    while colStart <= colEnd:
        midIndex = colStart + (colEnd - colStart) // 2 # Calculate the middle index
        
        # Check if the target is found at midIndex
        if arr[row][midIndex] == target:
            return [row, midIndex] # Return the found position
        elif arr[row][midIndex] < target:
            colStart = midIndex + 1 # Move the start column pointer up
        else:
            colEnd = midIndex - 1 # Move the end column pointer down
    
    # Return -1, -1 if the target is not found
    return [-1, -1]

if __name__ == "__main__":
    main()

