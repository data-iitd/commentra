
import java.util.Scanner;
public final class Main {
    private Main() {}
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt(); // Reading the number of rows for the 2D array
        int cols = scanner.nextInt(); // Reading the number of columns for the 2D array
        int[][] arr = new int[rows][cols]; // Initializing the 2D array with the given dimensions
        for (int i = 0; i < rows; i++) { // Looping through each row
            for (int j = 0; j < cols; j++) { // Looping through each column in the current row
                arr[i][j] = scanner.nextInt(); // Reading the element at position (i, j)
            }
        }
        int target = scanner.nextInt(); // Reading the target value to search for in the 2D array
        int[] result = binarySearch(arr, target); // Calling the binary search function to find the target
        System.out.println(result[0] + " " + result[1]); // Printing the result, which is the position of the target
        scanner.close(); // Closing the scanner to free up resources
    }
    static int[] binarySearch(int[][] arr, int target) {
        int rowCount = arr.length; // Getting the number of rows in the 2D array
        int colCount = arr[0].length; // Getting the number of columns in the 2D array
        if (rowCount == 1) { // If there's only one row, perform a simple binary search on that row
            return binarySearch(arr, target, 0, 0, colCount - 1);
        }
        int startRow = 0; // Initialize the start of the row search
        int endRow = rowCount - 1; // Initialize the end of the row search
        int midCol = colCount / 2; // Initialize the middle column index for the first iteration
        while (startRow < endRow - 1) { // Continue the row search until only two rows are left
            int midRow = startRow + (endRow - startRow) / 2; // Calculate the middle row index
            if (arr[midRow][midCol] == target) { // If the target is found in the middle row, return the position
                return new int[] {midRow, midCol};
            } else if (arr[midRow][midCol] < target) { // If the target is greater, move to the next half
                startRow = midRow;
            } else { // If the target is smaller, move to the previous half
                endRow = midRow;
            }
        }
        if (arr[startRow][midCol] == target) { // Check the first of the two remaining rows
            return new int[] {startRow, midCol};
        }
        if (arr[endRow][midCol] == target) { // Check the second of the two remaining rows
            return new int[] {endRow, midCol};
        }
        if (target <= arr[startRow][midCol - 1]) { // If the target is in the first half of the first row, search there
            return binarySearch(arr, target, startRow, 0, midCol - 1);
        }
        if (target >= arr[startRow][midCol + 1] && target <= arr[startRow][colCount - 1]) { // If the target is in the second half of the first row, search there
            return binarySearch(arr, target, startRow, midCol + 1, colCount - 1);
        }
        if (target <= arr[endRow][midCol - 1]) { // If the target is in the first half of the second row, search there
            return binarySearch(arr, target, endRow, 0, midCol - 1);
        }
        return binarySearch(arr, target, endRow, midCol + 1, colCount - 1); // Otherwise, search the second half of the second row
    }
    static int[] binarySearch(int[][] arr, int target, int row, int colStart, int colEnd) {
        while (colStart <= colEnd) { // Continue the search while there are columns to check
            int midIndex = colStart + (colEnd - colStart) / 2; // Calculate the middle column index
            if (arr[row][midIndex] == target) { // If the target is found, return the position
                return new int[] {row, midIndex};
            } else if (arr[row][midIndex] < target) { // If the target is greater, move to the next half
                colStart = midIndex + 1;
            } else { // If the target is smaller, move to the previous half
                colEnd = midIndex - 1;
            }
        }
        return new int[] {-1, -1}; // If the target is not found, return -1
    }
}
