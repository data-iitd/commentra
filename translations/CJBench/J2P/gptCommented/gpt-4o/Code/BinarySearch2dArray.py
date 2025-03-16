class Main:
    # Private constructor to prevent instantiation of the class
    def __init__(self):
        raise NotImplementedError("This class cannot be instantiated.")

    @staticmethod
    def main():
        # Read the number of rows and columns for the 2D array
        rows = int(input())
        cols = int(input())
        
        # Initialize a 2D array with the specified dimensions
        arr = []
        
        # Populate the 2D array with user input
        for _ in range(rows):
            row = list(map(int, input().split()))
            arr.append(row)
        
        # Read the target value to search for in the array
        target = int(input())
        
        # Perform binary search to find the target in the 2D array
        result = Main.binary_search(arr, target)
        
        # Output the result, which contains the row and column indices of the target
        print(result[0], result[1])

    @staticmethod
    def binary_search(arr, target):
        row_count = len(arr)  # Get the number of rows in the array
        col_count = len(arr[0])  # Get the number of columns in the array
        
        # If there is only one row, perform a binary search in that row
        if row_count == 1:
            return Main.binary_search_in_row(arr, target, 0, 0, col_count - 1)
        
        # Initialize pointers for the rows
        start_row = 0
        end_row = row_count - 1
        mid_col = col_count // 2  # Calculate the middle column index
        
        # Perform binary search on the rows
        while start_row < end_row - 1:
            mid_row = start_row + (end_row - start_row) // 2  # Calculate the middle row index
            
            # Check if the target is found at the middle column of the midRow
            if arr[mid_row][mid_col] == target:
                return [mid_row, mid_col]  # Return the found position
            elif arr[mid_row][mid_col] < target:
                start_row = mid_row  # Move the start row pointer up
            else:
                end_row = mid_row  # Move the end row pointer down
        
        # Check if the target is found in the startRow or endRow at the midCol
        if arr[start_row][mid_col] == target:
            return [start_row, mid_col]
        if arr[end_row][mid_col] == target:
            return [end_row, mid_col]
        
        # Determine which sub-column to search next based on the target's value
        if target <= arr[start_row][mid_col - 1]:
            return Main.binary_search_in_row(arr, target, start_row, 0, mid_col - 1)  # Search left sub-column
        if target >= arr[start_row][mid_col + 1] and target <= arr[start_row][col_count - 1]:
            return Main.binary_search_in_row(arr, target, start_row, mid_col + 1, col_count - 1)  # Search right sub-column
        if target <= arr[end_row][mid_col - 1]:
            return Main.binary_search_in_row(arr, target, end_row, 0, mid_col - 1)  # Search left sub-column in endRow
        
        # Search right sub-column in endRow
        return Main.binary_search_in_row(arr, target, end_row, mid_col + 1, col_count - 1)

    @staticmethod
    def binary_search_in_row(arr, target, row, col_start, col_end):
        # Perform binary search in the specified row between colStart and colEnd
        while col_start <= col_end:
            mid_index = col_start + (col_end - col_start) // 2  # Calculate the middle index
            
            # Check if the target is found at midIndex
            if arr[row][mid_index] == target:
                return [row, mid_index]  # Return the found position
            elif arr[row][mid_index] < target:
                col_start = mid_index + 1  # Move the start column pointer up
            else:
                col_end = mid_index - 1  # Move the end column pointer down
        
        # Return -1, -1 if the target is not found
        return [-1, -1]

# Call the main method to execute the program
Main.main()

# <END-OF-CODE>
