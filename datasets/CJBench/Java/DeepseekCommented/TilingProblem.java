import java.util.Scanner;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Static variable to keep track of the tile number
    private static int tile = 1;
    // 2D array to represent the board
    private static int[][] board;

    // Method to solve the tiling problem
    public static int[][] solveTiling(int size, int missingRow, int missingCol) {
        // Initialize the board with the given size
        board = new int[size][size];
        // Start filling the board recursively
        fillBoard(size, 0, 0, missingRow, missingCol);
        return board; // Return the completed board
    }

    // Recursive method to fill the board with tiles
    private static void fillBoard(int size, int row, int col, int missingRow, int missingCol) {
        // Base case: if the size of the board is 1, return
        if (size == 1) {
            return;
        }

        // Calculate half the size of the current board
        int half = size / 2;
        // Get the current tile number and increment it for the next tile
        int t = tile++;

        // Check if the missing tile is in the top-left quadrant
        if (missingRow < row + half && missingCol < col + half) {
            fillBoard(half, row, col, missingRow, missingCol); // Recur for the top-left quadrant
        } else {
            // Place a tile in the center of the top-left quadrant
            board[row + half - 1][col + half - 1] = t;
            fillBoard(half, row, col, row + half - 1, col + half - 1); // Recur for the top-left quadrant
        }

        // Check if the missing tile is in the top-right quadrant
        if (missingRow < row + half && missingCol >= col + half) {
            fillBoard(half, row, col + half, missingRow, missingCol); // Recur for the top-right quadrant
        } else {
            // Place a tile in the center of the top-right quadrant
            board[row + half - 1][col + half] = t;
            fillBoard(half, row, col + half, row + half - 1, col + half); // Recur for the top-right quadrant
        }

        // Check if the missing tile is in the bottom-left quadrant
        if (missingRow >= row + half && missingCol < col + half) {
            fillBoard(half, row + half, col, missingRow, missingCol); // Recur for the bottom-left quadrant
        } else {
            // Place a tile in the center of the bottom-left quadrant
            board[row + half][col + half - 1] = t;
            fillBoard(half, row + half, col, row + half, col + half - 1); // Recur for the bottom-left quadrant
        }

        // Check if the missing tile is in the bottom-right quadrant
        if (missingRow >= row + half && missingCol >= col + half) {
            fillBoard(half, row + half, col + half, missingRow, missingCol); // Recur for the bottom-right quadrant
        } else {
            // Place a tile in the center of the bottom-right quadrant
            board[row + half][col + half] = t;
            fillBoard(half, row + half, col + half, row + half, col + half); // Recur for the bottom-right quadrant
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner to read input
        // Read the size of the board and the position of the missing tile
        int size = scanner.nextInt();
        int missingRow = scanner.nextInt();
        int missingCol = scanner.nextInt();
        // Solve the tiling problem and get the result
        int[][] result = solveTiling(size, missingRow, missingCol);
        // Print the tiled board
        System.out.println("Tiled Board:");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(result[i][j] + " "); // Print each tile number
            }
            System.out.println(); // Move to the next line after each row
        }
        scanner.close(); // Close the scanner
    }
}
