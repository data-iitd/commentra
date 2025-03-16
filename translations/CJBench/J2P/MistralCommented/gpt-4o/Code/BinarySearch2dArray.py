class Main:
    @staticmethod
    def main():
        import sys
        
        # Read the number of rows and columns from the input
        rows, cols = map(int, sys.stdin.readline().split())

        # Create a 2D integer array to store the input data
        arr = [list(map(int, sys.stdin.readline().split())) for _ in range(rows)]

        # Read the target element to be searched in the 2D array
        target = int(sys.stdin.readline().strip())

        # Call the binarySearch method to find the indexes of the target element
        result = Main.binary_search(arr, target)

        # Print the indexes of the target element in the 2D array
        print(result[0], result[1])

    # Binary search method to find the indexes of the target element in a 1D sub-array
    @staticmethod
    def binary_search_1d(arr, target):
        start, end = 0, len(arr) - 1

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
    @staticmethod
    def binary_search_2d(arr, target, row, col_start, col_end):
        while col_start <= col_end:
            mid_index = col_start + (col_end - col_start) // 2

            if arr[row][mid_index] == target:
                return [row, mid_index]
            elif arr[row][mid_index] < target:
                col_start = mid_index + 1
            else:
                col_end = mid_index - 1

        # Return -1, -1 if the target element is not present in the sub-array
        return [-1, -1]

    # Binary search method to find the sub-array in which the target element may be present
    @staticmethod
    def binary_search(arr, target):
        row_count = len(arr)
        col_count = len(arr[0])

        if row_count == 1:
            # If the 2D array has only one row, treat it as a 1D array and call the binary_search method for 1D array
            return Main.binary_search_1d(arr[0], target)

        start_row, end_row = 0, row_count - 1
        mid_col = col_count // 2

        # Continue searching until the target element is found or the search range is empty
        while start_row < end_row - 1:
            mid_row = start_row + (end_row - start_row) // 2

            if arr[mid_row][mid_col] == target:
                return [mid_row, mid_col]
            elif arr[mid_row][mid_col] < target:
                start_row = mid_row
            else:
                end_row = mid_row

        # If the target element is found in the middle row, return its indexes
        if arr[start_row][mid_col] == target:
            return [start_row, mid_col]

        # If the target element is found in the last row, return its indexes
        if arr[end_row][mid_col] == target:
            return [end_row, mid_col]

        # If the target element is less than the middle element of the middle row, search in the left sub-array
        if target <= arr[start_row][mid_col - 1]:
            return Main.binary_search_2d(arr, target, start_row, 0, mid_col - 1)

        # If the target element is greater than the middle element of the middle row and less than or equal to the last element of the middle column, search in the right sub-array
        if target >= arr[start_row][mid_col + 1] and target <= arr[start_row][col_count - 1]:
            return Main.binary_search_2d(arr, target, start_row, mid_col + 1, col_count - 1)

        # If the target element is greater than the last element of the middle column, search in the sub-array of the last row
        if target > arr[start_row][col_count - 1]:
            return Main.binary_search_2d(arr, target, end_row, 0, col_count - 1)

        # If the target element is less than the first element of the middle column, search in the sub-array of the first row
        return Main.binary_search_2d(arr, target, start_row, 0, mid_col - 1)

# Entry point of the program
if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
