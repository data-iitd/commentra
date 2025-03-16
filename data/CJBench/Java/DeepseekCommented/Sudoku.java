import java.util.Scanner;

public class Main {
    // Function to check if it's safe to place a number in the given cell
    public static boolean isSafe(int[][] board, int row, int col, int num) {
        // Check if the number is already present in the current row
        for (int d = 0; d < board.length; d++) {
            if (board[row][d] == num) {
                return false; // Number found in the row
            }
        }
        // Check if the number is already present in the current column
        for (int r = 0; r < board.length; r++) {
            if (board[r][col] == num) {
                return false; // Number found in the column
            }
        }
        // Determine the size of the sub-grid
        int sqrt = (int) Math.sqrt(board.length);
        // Calculate the starting row and column indices of the sub-grid
        int boxRowStart = row - row % sqrt;
        int boxColStart = col - col % sqrt;
        // Check if the number is present in the current sub-grid
        for (int r = boxRowStart; r < boxRowStart + sqrt; r++) {
            for (int d = boxColStart; d < boxColStart + sqrt; d++) {
                if (board[r][d] == num) {
                    return false; // Number found in the sub-grid
                }
            }
        }
        return true; // Number can be placed safely
    }

    // Function to solve the Sudoku puzzle using backtracking
    public static boolean solveMain(int[][] board, int n) {
        int row = -1, col = -1; // Variables to store the row and column of an empty cell
        boolean isEmpty = true; // Flag to check if an empty cell is found

        // Find an empty cell in the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) { // Check for an empty cell
                    row = i;
                    col = j;
                    isEmpty = false; // Mark that an empty cell is found
                    break;
                }
            }
            if (!isEmpty) {
                break; // Exit if an empty cell is found
            }
        }
        // If no empty cell is found, the puzzle is solved
        if (isEmpty) {
            return true;
        }

        // Try placing numbers from 1 to n in the empty cell
        for (int num = 1; num <= n; num++) {
            // Check if it's safe to place the number
            if (isSafe(board, row, col, num)) {
                board[row][col] = num; // Place the number
                // Recursively attempt to solve the rest of the board
                if (solveMain(board, n)) {
                    return true; // Puzzle solved
                } else {
                    board[row][col] = 0; // Backtrack if placing the number didn't lead to a solution
                }
            }
        }
        return false; // No solution found
    }

    // Function to print the Sudoku board
    public static void print(int[][] board, int n) {
        for (int r = 0; r < n; r++) {
            for (int d = 0; d < n; d++) {
                System.out.print(board[r][d] + " "); // Print each number in the row
            }
            System.out.println(); // Move to the next line after each row
        }
    }

    // Main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner object for input
        int n = scanner.nextInt(); // Read the size of the board
        int[][] board = new int[n][n]; // Initialize the board

        // Read the board configuration from input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = scanner.nextInt(); // Fill the board with user input
            }
        }

        // Attempt to solve the Sudoku puzzle
        if (solveMain(board, n)) {
            print(board, n); // Print the solved board
        } else {
            System.out.println("No solution"); // Inform the user if no solution exists
        }
        scanner.close(); // Close the scanner
    }
}
