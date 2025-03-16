import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {}

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of rows and columns for the 2D array
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        
        // Initialize a 2D array with the specified dimensions
        int[][] arr = new int[rows][cols];
        
        // Populate the 2D array with user input
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = scanner.nextInt();
            }
        }
        
        // Read the target value to search for in the array
        int target = scanner.nextInt();
        
        // Perform binary search to find the target in the 2D array
        int[] result = binarySearch(arr, target);
        
        // Output the result, which contains the row and column indices of the target
        System.out.println(result[0] + " " + result[1]);
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Method to perform binary search on a 2D array
    static int[] binarySearch(int[][] arr, int target) {
        int rowCount = arr.length; // Get the number of rows in the array
        int colCount = arr[0].length; // Get the number of columns in the array
        
        // If there is only one row, perform a binary search in that row
        if (rowCount == 1) {
            return binarySearch(arr, target, 0, 0, colCount - 1);
        }
        
        // Initialize pointers for the rows
        int startRow = 0;
        int endRow = rowCount - 1;
        int midCol = colCount / 2; // Calculate the middle column index
        
        // Perform binary search on the rows
        while (startRow < endRow - 1) {
            int midRow = startRow + (endRow - startRow) / 2; // Calculate the middle row index
            
            // Check if the target is found at the middle column of the midRow
            if (arr[midRow][midCol] == target) {
                return new int[] {midRow, midCol}; // Return the found position
            } else if (arr[midRow][midCol] < target) {
                startRow = midRow; // Move the start row pointer up
            } else {
                endRow = midRow; // Move the end row pointer down
            }
        }
        
        // Check if the target is found in the startRow or endRow at the midCol
        if (arr[startRow][midCol] == target) {
            return new int[] {startRow, midCol};
        }
        if (arr[endRow][midCol] == target) {
            return new int[] {endRow, midCol};
        }
        
        // Determine which sub-column to search next based on the target's value
        if (target <= arr[startRow][midCol - 1]) {
            return binarySearch(arr, target, startRow, 0, midCol - 1); // Search left sub-column
        }
        if (target >= arr[startRow][midCol + 1] && target <= arr[startRow][colCount - 1]) {
            return binarySearch(arr, target, startRow, midCol + 1, colCount - 1); // Search right sub-column
        }
        if (target <= arr[endRow][midCol - 1]) {
            return binarySearch(arr, target, endRow, 0, midCol - 1); // Search left sub-column in endRow
        }
        
        // Search right sub-column in endRow
        return binarySearch(arr, target, endRow, midCol + 1, colCount - 1);
    }

    // Helper method to perform binary search in a specific row and column range
    static int[] binarySearch(int[][] arr, int target, int row, int colStart, int colEnd) {
        // Perform binary search in the specified row between colStart and colEnd
        while (colStart <= colEnd) {
            int midIndex = colStart + (colEnd - colStart) / 2; // Calculate the middle index
            
            // Check if the target is found at midIndex
            if (arr[row][midIndex] == target) {
                return new int[] {row, midIndex}; // Return the found position
            } else if (arr[row][midIndex] < target) {
                colStart = midIndex + 1; // Move the start column pointer up
            } else {
                colEnd = midIndex - 1; // Move the end column pointer down
            }
        }
        
        // Return -1, -1 if the target is not found
        return new int[] {-1, -1};
    }
}
