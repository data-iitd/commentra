import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {}

    // Constant for the base size of the grid
    private static final int BASE = 12; 

    // Possible moves for the knight in chess
    private static final int[][] MOVES = {
        {1, -2}, {2, -1}, {2, 1}, {1, 2},
        {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2},
    };

    // 2D array to represent the chessboard
    static int[][] grid;
    // Total number of squares to be covered by the knight
    static int total;

    // Method to reset the chessboard with a given size
    public static void resetBoard(int size) {
        // Initialize the grid with additional padding
        grid = new int[size + 4][size + 4];
        total = size * size; // Calculate total squares
        // Set the outer border of the grid to -1 (indicating invalid squares)
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (r < 2 || r >= grid.length - 2 || c < 2 || c >= grid[0].length - 2) {
                    grid[r][c] = -1; 
                }
            }
        }
    }

    // Recursive method to solve the knight's tour problem
    static boolean solve(int row, int col, int count) {
        // If all squares are covered, return true
        if (count > total) return true;

        // Get the list of valid neighboring moves
        List<int[]> neighbor = neighbors(row, col);
        // If no neighbors and not all squares are covered, return false
        if (neighbor.isEmpty() && count != total) return false;

        // Sort neighbors based on the number of further possible moves (Warnsdorff's rule)
        neighbor.sort(Comparator.comparingInt(a -> a[2]));

        // Try each neighbor
        for (int[] nb : neighbor) {
            int nextRow = nb[0];
            int nextCol = nb[1];
            grid[nextRow][nextCol] = count; // Mark the square as visited

            // Check for orphan condition and recursively solve for the next move
            if (!orphanDetected(count, nextRow, nextCol) && solve(nextRow, nextCol, count + 1)) {
                return true; // If solution found, return true
            }

            // Backtrack: unmark the square
            grid[nextRow][nextCol] = 0;
        }
        return false; // No solution found
    }

    // Method to find valid neighboring squares for the knight's next move
    static List<int[]> neighbors(int row, int col) {
        List<int[]> neighbor = new ArrayList<>();
        // Check all possible knight moves
        for (int[] m : MOVES) {
            int x = row + m[0];
            int y = col + m[1];
            // If the square is unvisited, add it to the neighbor list
            if (grid[x][y] == 0) {
                neighbor.add(new int[]{x, y, countNeighbors(x, y)});
            }
        }
        return neighbor; // Return the list of neighbors
    }

    // Method to count how many unvisited neighbors a square has
    static int countNeighbors(int row, int col) {
        int count = 0;
        // Check all possible knight moves
        for (int[] m : MOVES) {
            int x = row + m[0];
            int y = col + m[1];
            // Increment count if the neighbor is unvisited
            if (grid[x][y] == 0) count++;
        }
        return count; // Return the count of unvisited neighbors
    }

    // Method to detect if moving to a square creates an orphan situation
    static boolean orphanDetected(int count, int row, int col) {
        // Only check for orphan condition if not all squares are covered
        if (count < total - 1) {
            // Check neighbors of the current square
            for (int[] nb : neighbors(row, col)) {
                // If any neighbor has no unvisited neighbors, return true
                if (countNeighbors(nb[0], nb[1]) == 0) {
                    return true;
                }
            }
        }
        return false; // No orphan detected
    }

    // Method to print the solution of the knight's tour
    public static void printSolution(int size) {
        for (int r = 2; r < size + 2; r++) {
            for (int c = 2; c < size + 2; c++) {
                System.out.printf("%3d", grid[r][c]); // Print the grid with formatting
            }
            System.out.println(); // New line after each row
        }
    }

    // Main method to execute the knight's tour algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the size of the board and starting position from user input
        int size = scanner.nextInt();
        int startRow = scanner.nextInt();
        int startCol = scanner.nextInt();

        // Reset the board and mark the starting position
        resetBoard(size);
        grid[startRow + 2][startCol + 2] = 1;

        // Attempt to solve the knight's tour and print the result
        if (solve(startRow + 2, startCol + 2, 2)) {
            System.out.println("Knight's tour solution:");
            printSolution(size);
        } else {
            System.out.println("No solution exists."); // No solution found
        }
        scanner.close(); // Close the scanner
    }
}
