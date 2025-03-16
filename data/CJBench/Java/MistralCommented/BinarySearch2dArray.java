
import java.util.Scanner;

public final class Main {
    private Main() {}

    // Initialize scanner to read input from the console
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of rows and columns from the input
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();

        // Create a 2D integer array to store the input data
        int[][] arr = new int[rows][cols];

        // Read the elements of the 2D array from the input
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = scanner.nextInt();
            }
        }

        // Read the target element to be searched in the 2D array
        int target = scanner.nextInt();

        // Call the binarySearch method to find the indexes of the target element
        int[] result = binarySearch(arr, target);

        // Print the indexes of the target element in the 2D array
        System.out.println(result[0] + " " + result[1]);

        // Close the scanner to release the system resources
        scanner.close();
    }

    // Binary search method to find the indexes of the target element in a 1D sub-array
    static int[] binarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        // Continue searching until the target element is found or the search range is empty
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                return new int[] {mid, 0};
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Return -1, -1 if the target element is not present in the array
        return new int[] {-1, -1};
    }

    // Binary search method to find the indexes of the target element in a 2D array
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

        // Return -1, -1 if the target element is not present in the sub-array
        return new int[] {-1, -1};
    }

    // Binary search method to find the sub-array in which the target element may be present
    static int[] binarySearch(int[][] arr, int target) {
        int rowCount = arr.length;
        int colCount = arr[0].length;

        if (rowCount == 1) {
            // If the 2D array has only one row, treat it as a 1D array and call the binarySearch method for 1D array
            return binarySearch(arr[0], target);
        }

        int startRow = 0;
        int endRow = rowCount - 1;
        int midCol = colCount / 2;

        // Continue searching until the target element is found or the search range is empty
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

        // If the target element is found in the middle row, return its indexes
        if (arr[startRow][midCol] == target) {
            return new int[] {startRow, midCol};
        }

        // If the target element is found in the last row, return its indexes
        if (arr[endRow][midCol] == target) {
            return new int[] {endRow, midCol};
        }

        // If the target element is less than the middle element of the middle row, search in the left sub-array
        if (target <= arr[startRow][midCol - 1]) {
            return binarySearch(arr, target, startRow, 0, midCol - 1);
        }

        // If the target element is greater than the middle element of the middle row and less than or equal to the last element of the middle column, search in the right sub-array
        if (target >= arr[startRow][midCol + 1] && target <= arr[startRow][colCount - 1]) {
            return binarySearch(arr, target, startRow, midCol + 1, colCount - 1);
        }

        // If the target element is greater than the last element of the middle column, search in the sub-array of the last row
        if (target > arr[startRow][colCount - 1]) {
            return binarySearch(arr, target, endRow, 0, colCount - 1);
        }

        // If the target element is less than the first element of the middle column, search in the sub-array of the first row
        return binarySearch(arr, target, startRow, 0, midCol - 1);
    }
}