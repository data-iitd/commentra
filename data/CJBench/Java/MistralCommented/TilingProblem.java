
import java.util.Scanner;

// Final class to prevent instantiation from outside
public final class Main {
    private Main() {
    }

    // Private static variable to keep track of the next tile number
    private static int tile = 1;

    // Two dimensional array to store the tiled board
    private static int[][] board;

    // Method to solve the tiling problem and return the tiled board
    public static int[][] solveTiling(int size, int missingRow, int missingCol) {
        // Initialize the board with given size
        board = new int[size][size];

        // Recursive method to fill the board with tiles
        fillBoard(size, 0, 0, missingRow, missingCol);

        // Return the filled board
        return board;
    }

    // Recursive method to fill the board with tiles
    private static void fillBoard(int size, int row, int col, int missingRow, int missingCol) {
        // Base case: if size is 1, return
        if (size == 1) {
            return;
        }

        // Half the size of the board
        int half = size / 2;

        // Tile number to be placed
        int t = tile++;

        // Check the position of missing tile and fill accordingly
        if (missingRow < row + half && missingCol < col + half) {
            fillBoard(half, row, col, missingRow, missingCol); // Top left quadrant
        } else {
            // Place the tile at the current position
            board[row + half - 1][col + half - 1] = t;

            // Recursively fill the remaining quadrant
            fillBoard(half, row, col, row + half - 1, col + half - 1); // Top right quadrant
        }

        if (missingRow < row + half && missingCol >= col + half) {
            fillBoard(half, row, col + half, missingRow, missingCol); // Bottom left quadrant
        } else {
            // Place the tile at the current position
            board[row + half - 1][col + half] = t;

            // Recursively fill the remaining quadrant
            fillBoard(half, row, col + half, row + half - 1, col + half); // Bottom right quadrant
        }

        if (missingRow >= row + half && missingCol < col + half) {
            fillBoard(half, row + half, col, missingRow, missingCol); // Left half
        } else {
            // Place the tile at the current position
            board[row + half][col + half - 1] = t;

            // Recursively fill the remaining half
            fillBoard(half, row + half, col, row + half, col + half - 1); // Right half
        }

        if (missingRow >= row + half && missingCol >= col + half) {
            fillBoard(half, row + half, col + half, missingRow, missingCol); // Top right quadrant
        } else {
            // Place the tile at the current position
            board[row + half][col + half] = t;

            // Recursively fill the remaining quadrant
            fillBoard(half, row + half, col + half, row + half, col + half); // Bottom right quadrant
        }
    }

    // Main method to read input and print the tiled board
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input size, missing row, and missing column
        int size = scanner.nextInt();
        int missingRow = scanner.nextInt();
        int missingCol = scanner.nextInt();

        // Call the solveTiling method and print the tiled board
        int[][] result = solveTiling(size, missingRow, missingCol);
        System.out.println("Tiled Board:");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }

        // Close the scanner
        scanner.close();
    }
}

