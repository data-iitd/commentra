
import java.util.Scanner;

// Main class for solving Sudoku puzzle
public class Main {

    // Check if a number can be placed at given position in the board
    public static boolean isSafe(int[][] board, int row, int col, int num) {
        // Check row
        for (int d = 0; d < board.length; d++) {
            if (board[row][d] == num) {
                // Number already exists in the row, return false
                return false;
            }
        }

        // Check column
        for (int r = 0; r < board.length; r++) {
            if (board[r][col] == num) {
                // Number already exists in the column, return false
                return false;
            }
        }

        // Check box
        int sqrt = (int) Math.sqrt(board.length);
        int boxRowStart = row - row % sqrt;
        int boxColStart = col - col % sqrt;
        for (int r = boxRowStart; r < boxRowStart + sqrt; r++) {
            for (int d = boxColStart; d < boxColStart + sqrt; d++) {
                if (board[r][d] == num) {
                    // Number already exists in the box, return false
                    return false;
                }
            }
        }

        // Number is safe to place, return true
        return true;
    }

    // Solve the Sudoku puzzle recursively
    public static boolean solveMain(int[][] board, int n) {
        int row = -1, col = -1;
        boolean isEmpty = true;

        // Find empty cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) {
                    row = i;
                    col = j;
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty) {
                break;
            }
        }

        // If no empty cells are found, the puzzle is solved
        if (isEmpty) {
            return true;
        }

        // Try placing numbers from 1 to n in the empty cell
        for (int num = 1; num <= n; num++) {
            if (isSafe(board, row, col, num)) {
                board[row][col] = num;
                // Recursively solve the puzzle
                if (solveMain(board, n)) {
                    return true;
                } else {
                    // Backtrack if the recursive call fails
                    board[row][col] = 0;
                }
            }
        }

        // If no number can be placed in the empty cell, return false
        return false;
    }

    // Print the solved Sudoku puzzle
    public static void print(int[][] board, int n) {
        for (int r = 0; r < n; r++) {
            for (int d = 0; d < n; d++) {
                System.out.print(board[r][d] + " ");
            }
            System.out.println();
        }
    }

    // Main method to read input and call the solver
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the size of the Sudoku puzzle
        int n = scanner.nextInt();

        // Initialize the board with input
        int[][] board = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = scanner.nextInt();
            }
        }

        // Solve the puzzle and print the result
        if (solveMain(board, n)) {
            print(board, n);
        } else {
            System.out.println("No solution");
        }

        // Close the scanner
        scanner.close();
    }
}