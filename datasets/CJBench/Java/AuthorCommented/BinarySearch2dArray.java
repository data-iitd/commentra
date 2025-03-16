

import java.util.Scanner;

/**
 * This class provides a method to search for a target value in a 2D sorted
 * array.
 * The search is performed using a combination of binary search on rows and
 * columns.
 * The 2D array must be strictly sorted in both rows and columns.
 *
 * The algorithm works by:
 * 1. Performing a binary search on the middle column of the 2D array.
 * 2. Depending on the value found, it eliminates rows above or below the middle
 * element.
 * 3. After finding or eliminating rows, it further applies binary search in the
 * relevant columns.
 */
public final class BinarySearch2dArray {

    private BinarySearch2dArray() {}

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input: Number of rows and columns
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        int[][] arr = new int[rows][cols];

        // Input: 2D array elements
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = scanner.nextInt();
            }
        }

        // Input: Target value to search
        int target = scanner.nextInt();

        // Perform binary search
        int[] result = binarySearch(arr, target);

        // Output: Target position or [-1, -1] if not found
        System.out.println(result[0] + " " + result[1]);
        scanner.close();
    }

    /**
     * Performs a binary search on a 2D sorted array to find the target value.
     * The array must be sorted in ascending order in both rows and columns.
     *
     * @param arr    The 2D array to search in.
     * @param target The value to search for.
     * @return An array containing the row and column indices of the target, or [-1,
     *         -1] if the target is not found.
     */
    static int[] binarySearch(int[][] arr, int target) {
        int rowCount = arr.length;
        int colCount = arr[0].length;

        // Edge case: If there's only one row, search that row directly.
        if (rowCount == 1) {
            return binarySearch(arr, target, 0, 0, colCount - 1);
        }

        // Set initial boundaries for binary search on rows.
        int startRow = 0;
        int endRow = rowCount - 1;
        int midCol = colCount / 2;

        // Perform binary search on rows based on the middle column.
        while (startRow < endRow - 1) {
            int midRow = startRow + (endRow - startRow) / 2;

            if (arr[midRow][midCol] == target) {
                return new int[] {midRow, midCol};
            } else if (arr[midRow][midCol] < target) {
                startRow = midRow;
            } else {
                endRow = midRow;
            }
        }

        // If the target wasn't found during the row search, check the middle column of
        // startRow and endRow.
        if (arr[startRow][midCol] == target) {
            return new int[] {startRow, midCol};
        }
        if (arr[endRow][midCol] == target) {
            return new int[] {endRow, midCol};
        }

        // If target is smaller than the element in the left of startRow, perform a
        // binary search on the left of startRow.
        if (target <= arr[startRow][midCol - 1]) {
            return binarySearch(arr, target, startRow, 0, midCol - 1);
        }
        // If target is between midCol and the last column of startRow, perform a binary
        // search on that part of the row.
        if (target >= arr[startRow][midCol + 1] && target <= arr[startRow][colCount - 1]) {
            return binarySearch(arr, target, startRow, midCol + 1, colCount - 1);
        }
        // If target is smaller than the element in the left of endRow, perform a binary
        // search on the left of endRow.
        if (target <= arr[endRow][midCol - 1]) {
            return binarySearch(arr, target, endRow, 0, midCol - 1);
        }
        return binarySearch(arr, target, endRow, midCol + 1, colCount - 1);
    }

    /**
     * Performs a binary search on a specific row of the 2D array.
     *
     * @param arr      The 2D array to search in.
     * @param target   The value to search for.
     * @param row      The row index where the target will be searched.
     * @param colStart The starting column index for the search.
     * @param colEnd   The ending column index for the search.
     * @return An array containing the row and column indices of the target, or [-1,
     *         -1] if the target is not found.
     */
    static int[] binarySearch(int[][] arr, int target, int row, int colStart, int colEnd) {
        while (colStart <= colEnd) {
            int midIndex = colStart + (colEnd - colStart) / 2;

            if (arr[row][midIndex] == target) {
                return new int[] {row, midIndex};
            } else if (arr[row][midIndex] < target) {
                colStart = midIndex + 1;
            } else {
                colEnd = midIndex - 1;
            }
        }

        return new int[] {-1, -1};
    }
}
